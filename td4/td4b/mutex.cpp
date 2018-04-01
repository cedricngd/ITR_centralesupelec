#include "mutex.h"

Mutex::Mutex(bool isInversionSafe)
{
	pthread_mutexattr_t mutexAttribute; 									// 	Mutex attribute creation
	pthread_mutexattr_init(&mutexAttribute);								//	init Mutex attribute
	pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);	// 	set m a to PTHREAD_MUTEX_RECURSIVE

	if(isInversionSafe)
		pthread_mutexattr_setprotocol (&mutexAttribute, PTHREAD_PRIO_INHERIT);//	protection against priority inversion


	pthread_mutex_t mutex;													// 	mutex creation
	pthread_mutex_init(&mutex, &mutexAttribute);							//	init mutex

	pthread_mutexattr_destroy(&mutexAttribute);								//	destruction de l'attribut apres init mutex
	posixId = mutex;

	
	
	//pthread_mutex_destroy(&mutex); // TODO  main()

}

void  Mutex::lock(){
	pthread_mutex_lock(&posixId);
}

void  Mutex::unlock(){
	pthread_mutex_unlock(&posixId);
}
