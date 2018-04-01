#include "thread_fils.h"


#include<iostream>
using namespace std;

Thread_fils::Thread_fils(int* pCounter, int nLoops) 
: Thread(), pCounter(pCounter), nLoops(nLoops)
{
}


void Thread_fils::run(){
	for(int i=0;i<10000;i++){
		 *pCounter+=1;
	}
	
	cout << "terminé"<< *pCounter;
	//sleep_ms(3000);
	
}

