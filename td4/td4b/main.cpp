#include "thread_fils.h"
#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char* argv []){
	int counter=0;
	int nLoops = 1000000;
	int nTasks=2;			//TODO dynamic

	Mutex* mutex= new Mutex(true);

	vector<Thread_fils*> tvector;	

	for(int i=0;i<nTasks;i++){

		tvector.push_back(new Thread_fils(&counter, nLoops, mutex));
	}
	
	for(int i=0;i<nTasks;i++){
		tvector[i]->start(99);

	}

	//Thread::sleep_ms(2000);
	
	for(int i=0;i<nTasks;i++){
	
		while( not tvector[i]->join(2000) )
		{
			cout << "timeout reached "<< i<<endl; // test the join
		}
	}

	cout << counter <<endl;
/*
	for(int i=0;i<nTasks;i++){ // cree parfois des erreurs de seg...
		delete tvector[i];
	}*/ 
}
