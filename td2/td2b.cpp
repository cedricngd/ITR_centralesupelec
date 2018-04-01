#include<iostream>
#include<time.h>
#include<sstream>
#include<stdio.h>
#include<pthread.h>
#include<vector>

using namespace std;

struct Data{ 
			unsigned int nLoops;
			double counter;
			pthread_mutex_t mutex;
			bool toggle_mutex;
		};

void incr(Data* p_data);
void* call_incr (void* v_data);


	

int main(int argc, char* argv []){

	if(argc <3){
		cout << "erreur arguments"<<endl;
		return -1;	
	}
	Data data= {0,0};
	int unsigned nTasks;
	
	pthread_mutex_init(&data.mutex, NULL); // construction du mutex
	
	
	istringstream iss1 (argv[1]);
	iss1 >> data.nLoops;
	
	istringstream iss2 (argv[2]);
	iss2 >> nTasks;
	
	istringstream iss3 (argv[3]);
	iss3 >> data.toggle_mutex;
	
	/*
	istringstream iss(argv[1]+ " "+argv[1] + " "+ argv[2] + " "+ argv[3]);
	iss3 >> data.nLoops >> nTasks <<data.toggle_mutex;
	*/
	vector<pthread_t> incrementThreads;
	incrementThreads.resize(nTasks);
	

	struct timespec debut, fin, duree;
	clock_gettime(CLOCK_REALTIME, &debut);

	for(int i=0;i<nTasks;i++){
		pthread_create (&incrementThreads[i], NULL, call_incr, &data);
	}
	
	pthread_mutex_destroy(&data.mutex);
	for(int i=0;i<nTasks;i++){
		pthread_join(incrementThreads[i], NULL);
	}
		cout << "on compte jusqu'a " << data.counter << endl;
	
	clock_gettime(CLOCK_REALTIME, &fin);
	duree.tv_sec = fin.tv_sec - debut.tv_sec;
	if (fin.tv_nsec < debut.tv_nsec){
		duree.tv_sec -=1;
		fin.tv_nsec += 1e9;
	}

	duree.tv_nsec = fin.tv_nsec - debut.tv_nsec;
	cout << "cela a pris" <<duree.tv_sec + (duree.tv_nsec *1e-9) <<endl;
}

void incr(Data* p_data){
	
	if (p_data->toggle_mutex == 1){
		for(int i=0;i<p_data->nLoops;i++){
			pthread_mutex_lock(&p_data->mutex);

			p_data->counter+=1;
			pthread_mutex_unlock(&p_data->mutex);

		}
	}
	else{
		for(int i=0;i<p_data->nLoops;i++){
			p_data->counter+=1;
		}
	}
	
	
}

void* call_incr (void* v_data){

		Data* p_data = (Data*) v_data;
		incr(p_data);
		return v_data;
}




