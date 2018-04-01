#include "thread_fils.h"
#include<iostream>
using namespace std;

Thread_fils::Thread_fils(int* pCounter, int nLoops, Mutex* pmutex, Condition* pcondition)
: Thread(SCHED_RR), pCounter(pCounter), nLoops(nLoops),m_pmutex(pmutex),m_pcondition(pcondition)
{

}


void Thread_fils::run(){
	if (started){
		m_pcondition->wait(m_pcondition->posixId,m_pmutex);
		cout << "sortie du wait"<<endl;
	}
	for(int i=0;i<10000;i++){
		m_pmutex->lock();
		*pCounter+=1;
		m_pmutex->unlock();
	}

	
}

