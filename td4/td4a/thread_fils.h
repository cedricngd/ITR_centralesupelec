#include "thread.h"

class Thread_fils: public Thread{
	private:
	int* pCounter;
	int nLoops;	
	
	public:
	Thread_fils(int* pCounter, int nLoops);

	protected:
	void run();
};
