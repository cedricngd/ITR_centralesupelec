#include <pthread.h>

class Mutex {
private: 
	pthread_mutex_t posixId;

public:
	Mutex(bool isInversionSafe=true);
	void lock();
	void unlock();
protected:

};



