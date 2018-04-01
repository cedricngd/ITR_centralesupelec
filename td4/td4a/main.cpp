#include "thread_fils.h"
#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char* argv []){
	int counter=0;
	int nLoops = 1000000;
	int nTasks=1;			//TODO dynamic
	vector<Thread_fils*> tvector;	

	for(int i=0;i<nTasks;i++){
		tvector.push_back(new Thread_fils(&counter, nLoops));
	}
	
	for(int i=0;i<nTasks;i++){
		tvector[i]->start(0);

	}

	//Thread::sleep_ms(2000);
	
	for(int i=0;i<nTasks;i++){
	
		while( not tvector[i]->join(2500) )
		{
			cout << "join "<<endl;
		}
	}
	cout << counter <<endl;
	for(int i=0;i<nTasks;i++){
		delete tvector[i];
	}
}
