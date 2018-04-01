#include "thread_fils.h"
using namespace std;


int main(int argc, char* argv []){
	int counter=0;
	int nLoops = 1000000;
	int nTasks=20;			//TODO dynamic

	Mutex* mutex= new Mutex(true);
	Condition* condition= new Condition(true);	

	Thread_fils* tf=new Thread_fils(&counter, nLoops, mutex,condition));
	tf->start(99);
	tf->start(99);

	tf->join(2000);
	cout << counter <<endl;
	/*
	for(int i=0;i<nTasks;i++){ // cree parfois des erreurs de seg...
		delete tvector[i];
	}*/ 
}




















