#include "condition.h"

Condition::Condition(){
	pthread_cond_init(&posixId, nullptr);
}

void Condition::wait(pthread_mutex_t mutex){
	pthread_cond_wait(&posixId,&mutex);
}

void Condition::notify(){
	thread_cond_signal(&posixId);
}
