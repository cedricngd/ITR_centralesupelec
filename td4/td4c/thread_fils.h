#include "thread.h"
#include "condition.h"
#include "mutex.h"

class Thread_fils: public Thread{
	private:
	int* pCounter;
	int nLoops;	
	Mutex* m_pmutex;
	Condition* m_pcondition;
	public:
	Thread_fils(int* pCounter, int nLoops, Mutex* m_pmutex,Condition* pcondition);

	protected:
	void run();
};
