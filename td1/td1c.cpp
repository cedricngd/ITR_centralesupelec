#include<iostream>
#include<time.h>
#include<sstream>
#include<stdio.h>
#include<limits.h>
#include<signal.h>

using namespace std;

unsigned long incr(unsigned int nLoops, double* pCounter,volatile bool * pStop);
void timerInit(volatile bool* pStop,timer_t* tid,int nsec);
void calib(double iLoops_4s, double iLoops_6s);

int main(int argc, char* argv []){

	volatile int compteur=0; 

		timer_t tid;

	volatile bool stop = false;
	double counter_4s = 0;
	double counter_6s = 0;
	unsigned int nLoops=UINT_MAX;
	double iLoops_4s;
	double iLoops_6s;

	
	struct timespec debut_4s, fin_4s, duree_4s;
	struct timespec debut_6s, fin_6s, duree_6s;
	
	//***************************************************************************************
	// incrementation pendant 4s
	timerInit(&stop, &tid,4);

	clock_gettime(CLOCK_REALTIME, &debut_4s);
	iLoops_4s = incr(nLoops, &counter_4s, &stop);
	clock_gettime(CLOCK_REALTIME, &fin_4s);

	duree_4s.tv_sec = fin_4s.tv_sec - debut_4s.tv_sec;
	if (fin_4s.tv_nsec < debut_4s.tv_nsec){
		duree_4s.tv_sec -=1;
		fin_4s.tv_nsec += 1e9;
	}
	duree_4s.tv_nsec = fin_4s.tv_nsec - debut_4s.tv_nsec;

	cout << "l'execution de "<< iLoops_4s<<" boucles a pris "<< duree_4s.tv_sec + (duree_4s.tv_nsec *1e-9) << " secondes." << endl;
	cout 	<<endl;

	//***************************************************************************************
	// incrementation pendant 6s
	
	timerInit(&stop, &tid,6);

	clock_gettime(CLOCK_REALTIME, &debut_6s);
	iLoops_6s = incr(nLoops, &counter_6s, &stop);
	clock_gettime(CLOCK_REALTIME, &fin_6s);

	duree_6s.tv_sec = fin_6s.tv_sec - debut_6s.tv_sec;
	if (fin_6s.tv_nsec < debut_6s.tv_nsec){
		duree_6s.tv_sec -=1;
		fin_6s.tv_nsec += 1e9;
	}
	duree_6s.tv_nsec = fin_6s.tv_nsec - debut_6s.tv_nsec;

	cout << "l'execution de "<< iLoops_6s<<" boucles a pris "<< duree_6s.tv_sec + (duree_6s.tv_nsec *1e-9) << " secondes." << endl;
	
	//***************************************************************************************
	// calcul a et b
	
	calib (iLoops_4s, iLoops_6s);
	
	return 0;
}


void calib(double iLoops_4s, double iLoops_6s){
	double b = (3*iLoops_4s) - 2*iLoops_6s;
	double a= 0.5*iLoops_6s-0.5*iLoops_4s;
	cout << "b= " << b<< endl; 
	cout << "a= " << a; 
}


unsigned long incr(unsigned int nLoops, double* pCounter,volatile bool* pStop){
	long iLoops;
	*pStop=false;
	for(iLoops=0;iLoops<nLoops and *pStop == false;iLoops++){
		*(pCounter)+=1;	
	}
	//cout<< iLoops << " boucles sur "<< nLoops << " ont été effectuées, on a compté jusqu'a: "<< *(pCounter) <<endl;
	return iLoops;
}


void myHandler(int sig, siginfo_t* si, void*){
	volatile bool* pStop = (volatile bool*) si->si_value.sival_ptr;
	*pStop=true;
}


void timerInit(volatile bool* pStop,timer_t* tid, int nsec){

	struct sigaction sa;
	sa.sa_flags= SA_SIGINFO;
	sa.sa_sigaction = myHandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN,&sa, NULL);

	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr= (void*)pStop;

	
	timer_create(CLOCK_REALTIME, &sev, tid);
	itimerspec its;
	its.it_value.tv_sec = nsec;			//	secondes de la premiere periode
	its.it_value.tv_nsec =0 ;			// 	nsecondes de la premiere periode
	its.it_interval.tv_sec = 0;			//	secondes des periodes suivantes
	its.it_interval.tv_nsec = 0;			//	nsecondes des periodes suivantes
	timer_settime(*tid, 0, &its, NULL);

	}

