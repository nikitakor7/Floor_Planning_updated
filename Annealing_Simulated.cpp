/*
* This file runs Simulated Annealing to find the optimum area for floorplanning
* @Author : Nikita Korgaonkar
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<random>
#include<time.h>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include"polish_final.h"
#include"moves.h"
#include"area123.h"
#include<random>
#include<math.h>


using namespace std;
bool acceptMove(float del_cost, int T)
{
	bool k;
	int accepted_move;
	float boltz, random_number;
	const double boltzmann_constant = 1.3806503e-23;
	if(del_cost < 0)
	{
		k = 1;
		accepted_move++;
		
		}	
	
	else
	{
		boltz = exp(-1* del_cost/(boltzmann_constant*T));
		random_number=(double) (rand()/ (double) RAND_MAX);
		if(random_number<boltz)
		{
			k=1;
		//	accepted_move++;
		}
			
		else
			k=0;
		cout<< "Accepted moves are:"<<accepted_move;
	}	
	
return k;	
}

int coolDown(int T)
{
	T = 0.95*T;
}
float simulated_annealing()
{
	srand(time(0));
	string curSolution, random_initial_solution, nextSol;
	random_initial_solution = postfix;
	curSolution = random_initial_solution ;
	bool decide;
	float T = 40000;
	float Tfreez = 0.001;
	int NUM_MOVES_PER_TEMP_STEP = 30 ;
	float delta_cost;
	
	while(T>Tfreez)
	{
		for(int i =0; i<NUM_MOVES_PER_TEMP_STEP; i++)
		{
			//cout <<"hi";
			cout<<"\n"<<"************************************************";
			nextSol = moves(curSolution);
			delta_cost = area123(nextSol)-area123(curSolution);
			decide = acceptMove(delta_cost,T );
			cout<<"Current Solution"<<curSolution<<endl;
			cout<<"Next Solution"<<nextSol<<endl;
			cout<<"delta cost"<<delta_cost<<endl;
			if(decide == true)
			{
				curSolution = nextSol;
				cout << "Accepted Move"<<curSolution<<endl;
			}
			T = 0.95*T;
			// coolDown(T);
		}
	}
	cout << "Final _ Area is : "<<area123(curSolution)/1.5<<endl;
return(area123(curSolution))	;		
			
}
	

