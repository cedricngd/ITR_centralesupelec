#include <pthread.h>

class Thread {
private: 
	pthread_t posixId;
	static void* call_run(void* aThread);
public:
	//Thread(int schedPolicy= SCHED_OTHER);
	Thread();
	void start(int priority);
	void join();
protected:

	virtual void run()=0;
};



