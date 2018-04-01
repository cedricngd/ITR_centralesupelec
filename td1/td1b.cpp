	#include<iostream>
#include<time.h>
#include<sstream>
#include<stdio.h>
using namespace std;

void incr(unsigned int nLoops, double* pCounter);


int main(int argc, char* argv []){

	if( argc < 2){
		cerr<< "ERREUR: Le programme prend un argument (nombre de boucle)"<< endl;
		return -1;
	}

	unsigned int nLoops;
	istringstream iss(argv[1]);
	iss >> nLoops;
	double counter = 0;
	
	struct timespec debut, fin, duree;
	clock_gettime(CLOCK_REALTIME, &debut);

	incr(nLoops, &counter);

	clock_gettime(CLOCK_REALTIME, &fin);
	duree.tv_sec = fin.tv_sec - debut.tv_sec;
	if (fin.tv_nsec < debut.tv_nsec){
		duree.tv_sec -=1;
		fin.tv_nsec += 1e9;
	}
	duree.tv_nsec = fin.tv_nsec - debut.tv_nsec;

	cout << "On a compté jusqu'a " << counter;
	cout << " et ça a pris "<< duree.tv_sec + (duree.tv_nsec *1e-9) << " secondes." << endl;

	return 0;
}

void incr(unsigned int nLoops, double* pCounter){
	for(int i=0;i<nLoops;i++){
		*(pCounter)+=1;
	}
}
