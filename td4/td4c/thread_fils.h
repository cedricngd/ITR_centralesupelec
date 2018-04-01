#include "thread.h"
#include "mutex.h"

class Thread_fils: public Thread{
	private:
	int* pCounter;
	int nLoops;	
	Mutex* m_pmutex;
	
	public:
	Thread_fils(int* pCounter, int nLoops, Mutex* m_pmutex);

	protected:
	void run();
};