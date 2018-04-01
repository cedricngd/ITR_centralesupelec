#include<iostream>
#include<time.h>
#include<sstream>
#include<stdio.h>
#include<pthread.h>
#include<vector>

using namespace std;

void incr(unsigned int nLoops, volatile double* pCounter);
void* call_incr (void* v_data);


struct Data{ 
			unsigned int nLoops;
			volatile double counter;

		};	

int main(int argc, char* argv []){

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
		pthread_create (&incrementThreads[i], NULL, call_incr, &data);
	}
	
	
	for(int i=0;i<nTasks;i++){
		pthread_join(incrementThreads[i], NULL);
	}
	cout << "on compte jusqu'a " << data.counter << endl;
	
}

void incr(unsigned int nLoops, volatile double* pCounter){
	for(int i=0;i<nLoops;i++){
		*(pCounter)+=1;
	}

	
}

void* call_incr (void* v_data){

		Data* p_data = (Data*) v_data;


		incr(p_data->nLoops,&(p_data->counter));
		return v_data;
}




