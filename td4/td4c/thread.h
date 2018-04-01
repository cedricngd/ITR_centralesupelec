#include <pthread.h>
#include<iostream>

class Thread {
private: 
	pthread_t posixId;
	pthread_attr_t posixAttr;
	int schedPolicy;
	static void* call_run(void* aThread);
	
public:
	Thread(int schedPolicy= SCHED_OTHER);
	//Thread(pthread_t, int schedPolicy, int priority);
	void setSchedPolicy(int schedPolicy, int priority);
	void start(int priority);
	void join();
	bool join (double timeout_ms);
	static void sleep_ms(double delay_ms);
protected:
	bool started=false;
	virtual void run()=0;
};



