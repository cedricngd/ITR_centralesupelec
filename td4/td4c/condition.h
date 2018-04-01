#include <pthread.h>
#include<iostream>

class Condition {
private: 
	pthread_cond_t posixId;

	
public:
	Condition();
	void wait(pthread_mutex_t);
	void notify (); 
	
protected:
};



