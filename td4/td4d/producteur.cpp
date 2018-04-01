#include "producteur.h"
using namespace std;

Producteur::Producteur()
: Thread(SCHED_RR)
{

}


void Producteur::run(){
	cout<< "Salut je suis producteur"<<endl;
/*
	for(int i=0;i<10000;i++){
		m_pmutex->lock();
		*pCounter+=1;
		m_pmutex->unlock();
	}*/
	
}

