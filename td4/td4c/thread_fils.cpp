#include "thread_fils.h"
#include<iostream>
using namespace std;

Thread_fils::Thread_fils(int* pCounter, int nLoops, Mutex* pmutex)
: Thread(SCHED_RR), pCounter(pCounter), nLoops(nLoops),m_pmutex(pmutex)
{

}


void Thread_fils::run(){
	for(int i=0;i<10000;i++){
		m_pmutex->lock();
		*pCounter+=1;
		m_pmutex->unlock();
	}
	
	
}

