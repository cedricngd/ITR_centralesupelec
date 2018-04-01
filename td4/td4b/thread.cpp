#include "thread.h"
#include<iostream>

using namespace std;

Thread::Thread(int schedPolicy){
	this->schedPolicy=schedPolicy;
}


void Thread::start(int priority){
	pthread_create (&posixId, NULL,call_run, this);
	setSchedPolicy(schedPolicy, priority);
}
void Thread::setSchedPolicy(int schedPolicy,int priority){
     int ret;
	pthread_t this_thread = pthread_self();

	// struct sched_param is used to store the scheduling priority
     struct sched_param params;

	// We'll set the priority
     params.sched_priority = priority;
 
     // Attempt to set thread real-time priority to the <schedPolicy> policy
     ret = pthread_setschedparam(this_thread, schedPolicy, &params);
     if (ret != 0) {
         cout << "Unsuccessful in setting thread params, error: "<< ret << endl;
         return;     
     }
}



void Thread::join(){
	pthread_join(posixId, NULL);
}

bool Thread::join(double delay_ms){
	struct timespec delay_ts,deadline;

	delay_ts.tv_sec= delay_ms/1000;
	delay_ts.tv_nsec= (delay_ms - delay_ts.tv_sec*1000)*1000000;

 	
	if (clock_gettime(CLOCK_REALTIME,&deadline)==-1){
		cerr<< "Error in getClockTime"<<endl;
	}	
	deadline.tv_sec += delay_ts.tv_sec;
	deadline.tv_nsec += delay_ts.tv_nsec;
	if(delay_ts.tv_nsec > 1000*1000*1000 ){
		deadline.tv_sec+=1;
		deadline.tv_nsec-=1000*1000*1000;
	}
	

	return pthread_timedjoin_np(posixId, NULL, &deadline) != ETIMEDOUT;	//	pthread_timedjoin_np prend un temps absolu, 
																		//	retourne  ETIMEDOUT si time out arrive avant la fin du thread

}


void  Thread::sleep_ms(double delay_ms){

	struct timespec delay_ts,remainder;

	delay_ts.tv_sec= delay_ms/1000;
	delay_ts.tv_nsec= (delay_ms - delay_ts.tv_sec*1000)*1000000;
	remainder = delay_ts;

	while (nanosleep(&delay_ts,&remainder)!=0){ // prend un delai
		delay_ts=remainder;
	}		
}



void*Thread:: call_run(void* aThread){

	Thread* t = (Thread*) aThread;
	t -> run ();

}
