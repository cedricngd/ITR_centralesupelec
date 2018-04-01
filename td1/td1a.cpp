#include<iostream>
#include<time.h>
#include<signal.h>
#include<stdio.h>
using namespace std;

void myHandler(int,siginfo_t*,void*);
void timerInit(volatile int*,timer_t*);

int main(){
	volatile int compteur=0; 		// volatile car aprés on fait une boucle vide
	timer_t tid;
	timerInit(&compteur,&tid);

	for(int i =0;i<300000000;i++);		// give time to the timer to reach 15 before main finish

	timer_delete(tid);
}

void myHandler(int sig, siginfo_t* si, void*){
	volatile int* ptr_cpt = (volatile int*) si->si_value.sival_ptr;
	while (*(ptr_cpt) <15){
		
		*(ptr_cpt)=*(ptr_cpt)+1;
		cout<<"Valeur du compteur: " <<*(ptr_cpt)<<endl;
	}
}

void timerInit(volatile int* compteur,timer_t* tid){

	struct sigaction sa;
	sa.sa_flags= SA_SIGINFO;
	sa.sa_sigaction = myHandler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGRTMIN,&sa, NULL);

	struct sigevent sev;
	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGRTMIN;
	sev.sigev_value.sival_ptr= (void*)compteur;

	
	timer_create(CLOCK_REALTIME, &sev, tid);
	itimerspec its;
	its.it_value.tv_sec = 0;			//	secondes de la premiere periode
	its.it_value.tv_nsec =500000000 ;		// 	nsecondes de la premiere periode
	its.it_interval.tv_sec = 0;			//	secondes des periodes suivantes
	its.it_interval.tv_nsec = 500000000;		//	nsecondes des periodes suivantes
	timer_settime(*tid, 0, &its, NULL);

}
