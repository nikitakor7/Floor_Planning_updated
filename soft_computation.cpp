/*
*
* This file finds a combination of widths and heights for Soft Blocks Computation
* @ Author : Nikita Korgaonkar
*
*/
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include <stack>
#include <limits>
#include<malloc.h>
#include<string>
#include"polish_final.h"
#include "Project_1.h"
#include"soft_computation.h"
#include <utility>
#include<vector>
#include"vertical_slicing.h"
#include"horizontal_slicing.h"
#include<bits/stdc++.h>

using namespace std;

vector<pair<float, float> > myVec1;
vector<pair<float, float> > myVec2;
vector<pair<float, float> > myVec3;
stack<char>mystack;

float soft_computation()
{
	int op1 , op2;
	string post = postfix; //checked
	for(int i =0; i<post.length()-1; i++)
	{
		if(isdigit(post[i]))
		{
			mystack.push(post[i]);
		//	cout <<"val"<< mystack.top()<<endl;
		}
		else
		{
			if(!mystack.empty())
			{
				op1 = mystack.top() - '0';
				mystack.pop();
				cout << "op1"<< op1<< endl;
			}
			if(!mystack.empty())
			{
				op2 = mystack.top() - '0';
				mystack.pop();
			}
			if(post[i] == '+')
			{
				//float k = ideal_val[op1] - '0';
				//cout<<"\n"<<"op1"<<op1<<endl;
					myVec1.push_back(make_pair(ideal_val[op1] , ideal_val[op1]));
					myVec1.push_back(make_pair(ideal_val[op1]/(sqrt(min_ratio[i])),min_ratio[op1]*(ideal_val[op1])/(sqrt(min_ratio[op1]))));
					myVec1.push_back(make_pair(ideal_val[op1]/(sqrt(max_ratio[i])), max_ratio[op1]*(ideal_val[op1])/(sqrt(max_ratio[op1])) ));
					cout <<"vec1"<< post[i]<<"\t"<<myVec1[1].first;
					//------------------------------------------------------------------------
					//k = ideal_val[op2];
					if(i == 2) // only for first element
					{
					myVec2.push_back(make_pair(ideal_val[op1] , ideal_val[op1]));
					myVec2.push_back(make_pair(ideal_val[op1]/(sqrt(min_ratio[i])),min_ratio[op2]*(ideal_val[op1])/(sqrt(min_ratio[op2]))));
					myVec2.push_back(make_pair(ideal_val[op1]/(sqrt(max_ratio[i])), max_ratio[op2]*(ideal_val[op1])/(sqrt(max_ratio[op2]))) );
						
					}
					else
					{/*
						myVec2.push_back(make_pair());
						myVec2.push_back(make_pair());
						myVec2.push_back(make_pair());
					*/	
					}
					compute_vertical_slicing( );
				
			}
			else if(post[i] == '-')
			{
				//float k = ideal_val[op1];
				myVec1.push_back(make_pair(ideal_val[op1] , ideal_val[op1]));
				myVec1.push_back(make_pair(ideal_val[op1]/(sqrt(min_ratio[i])),min_ratio[op1]*(ideal_val[op1])/(sqrt(min_ratio[op1]))));
				myVec1.push_back(make_pair(ideal_val[op1]/(sqrt(max_ratio[i])), max_ratio[op1]*(ideal_val[op1])/(sqrt(max_ratio[op1])) ));
			
				//*******************************************************************
				//k = ideal_val[op2];
				myVec2.push_back(make_pair(ideal_val[op1] , ideal_val[op1]));
				myVec2.push_back(make_pair(ideal_val[op1]/(sqrt(min_ratio[i])),min_ratio[op2]*(ideal_val[op1])/(sqrt(min_ratio[op2]))));
				myVec2.push_back(make_pair(ideal_val[op1]/(sqrt(max_ratio[i])), max_ratio[op2]*(ideal_val[op1])/(sqrt(max_ratio[op2]))) );
			//	compute_horizontal_slicing();
			}
		}
		
	}
	
	for(int i =0; i< myVec1.size(); i++)
	{
		cout << " my Vec 1"<<myVec1[i].first <<"\t";
	}
}
	
   
