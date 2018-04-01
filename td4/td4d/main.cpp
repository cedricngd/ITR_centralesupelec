#include "consommateur.h"
#include "producteur.h"
#include<vector>
using namespace std;


int main(int argc, char* argv []){

	int nProd = 2;
	int nCons = 2;
	
	vector<Producteur*> prodvector;	
	vector<Consommateur*> consvector;	

	for(int i=0;i<nProd;i++){
		prodvector.push_back(new Producteur());
	}
	for(int i=0;i<nCons;i++){
		consvector.push_back(new Consommateur());
	}

	
	// start prod threads
	for(int i=0;i<nProd;i++){
		prodvector[i]->start(99);
	}

	// start cons threads
	for(int i=0;i<nCons;i++){
		consvector[i]->start(99);
	}

	// join prod threads
	for(int i=0;i<nProd;i++){
		while( not prodvector[i]->join(2000))
		{
			cout << "join timeout reached !"<<endl;
		}
	}
	// join cons threads
	for(int i=0;i<nCons;i++){
		while( not consvector[i]->join(2000))
		{
			cout << "join timeout reached !"<<endl;
		}
	}

	//cout << counter <<endl;
/*
	for(int i=0;i<nTasks;i++){ // cree parfois des erreurs de seg...
		delete tvector[i];
	}*/ 
}
