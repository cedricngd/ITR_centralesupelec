#ifndef THREAD
#define THREAD
#include "thread.h"
#endif
class Consommateur: public Thread{
	private:

	public:
	Consommateur();

	protected:
	void run();
};

