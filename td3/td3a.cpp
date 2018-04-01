#include<iostream>
#include<time.h>
#include<sstream>
#include<stdio.h>
#include<pthread.h>
//#include<vector>

using namespace std;

class Chrono{ 
	private:
		timespec startTime_, stopTime_;
	public:
		void Chrono();
		void stop();
		void restart();
		bool isActive();
	
		};
	

int main(int argc, char* argv []){

	
}




