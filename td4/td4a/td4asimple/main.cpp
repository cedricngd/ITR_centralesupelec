#include "thread_fils.h"
#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char* argv []){
	int counter=0;
	int nLoops = 1000000;
	int nTasks=2;

	vector<Thread_fils*> tvector;	

	for(int i=0;i<nTasks;i++){
		tvector.push_back(new Thread_fils(&counter, nLoops));
	}
	
	for(int i=0;i<nTasks;i++){
		tvector[i]->start(0);

	}
	//Thread_fils fils(&counter, nLoops);

	//fils.start(0); // start du pere
	
	//fils.join();



	/*
	if(argc <2){
		cout << "erreur arguments"<<endl;
		return -1;	
	}
	Data data= {0,0};


	
	istringstream iss1 (argv[1]);
	iss1 >> data.nLoops;
	
	int unsigned nTasks;
	
	istringstream iss2 (argv[2]);
	iss2 >> nTasks;
	
	
	vector<pthread_t> incrementThreads;
	incrementThreads.resize(nTasks);
	for(int i=0;i<nTasks;i++){
		
	}
	
	
	for(int i=0;i<nTasks;i++){
		pthread_join(incrementThreads[i], NULL);
	}
	cout << "on compte jusqu'a " << data.counter << endl;
	*/
	
	for(int i=0;i<nTasks;i++){
		tvector[i]->join();
	}

	cout << counter <<endl;
	for(int i=0;i<nTasks;i++){
		delete tvector[i];
	}
}
