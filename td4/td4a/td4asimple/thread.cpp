#include "thread.h"
#include<iostream>
using namespace std;

Thread::Thread(){
}


void Thread::start(int priority){
	pthread_create (&posixId, NULL,call_run, this); // this : le thread actuel


}

void Thread::join(){

	pthread_join(posixId, NULL);
}



void*Thread:: call_run(void* aThread){

	Thread* t = (Thread*) aThread;
	t -> run ();
}
