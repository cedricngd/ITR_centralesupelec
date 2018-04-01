#include "consommateur.h"
using namespace std;

Consommateur::Consommateur()
: Thread(SCHED_RR)
{

}


void Consommateur::run(){
		cout<< "Salut je suis Consommateur"<<endl;
/*
	for(int i=0;i<10000;i++){
		m_pmutex->lock();
		*pCounter+=1;
		m_pmutex->unlock();
	}
*/
	
}

