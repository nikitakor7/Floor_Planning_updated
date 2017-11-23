/*
This program computes the total area of the bounding box for a particular polish expression
author : Nikita Korgaonkar 
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<stack>
#include<math.h>
#include <algorithm>    // std::max
#include"Project_1.h"
#include"polish_final.h"


using namespace std;
std::vector <float> wt1;
std::vector <float> ht1;
std::vector <float> area1;

float area123(string post)
{
	std::stack<char> mystack;
	std::stack<float> mywidth;
	std::stack<float> myht;
	wt1 =  wt_val;
	for(int i =0; i< wt1.size()-1 ;i++)
	{
		//cout<<wt1[i]<<" ";
	}
	ht1 = ht_val;
	string new_string;
	float W_new, H_new;
	//cout<<"area of each block is:";
	for(int i =0; i< wt1.size()-1; i++)
	{
		int k = wt1[i]*ht1[i];
		//cout <<"k"<<k<<endl;
		area1.push_back(k);
		//cout<<area1[i]<<" ";
	}

//Finding the area of the bounding box
cout <<endl;
float w_1, h_1, w_2, h_2;
for(int i = 0; i<post.length()+1;i++)
{
	if(isdigit(post[i]))
	{
		mystack.push(post[i]);
		float r = post[i] - '0';
		mywidth.push(wt1[r]);
		myht.push(ht1[r]);
		//cout<< ht1[post[i]];
	}
	else
	{
		char op1, op2;
		if(!mystack.empty())
		{
		op1 = mystack.top();
		w_1 = mywidth.top();
		h_1 = myht.top();
		mystack.pop();
		mywidth.pop();
		myht.pop();
		
		}
		
		if(!mystack.empty())
		{
		op2 = mystack.top();
		w_2 = mywidth.top();
		h_2 = myht.top();
		
		mystack.pop();
		mywidth.pop();
		myht.pop();
		}
		
		if(post[i] == '+')
		{
			W_new = w_1 + w_2;
			H_new = max(h_1,h_2);
			//cout<<"W"<<"\t"<<"H"<<W_new<<"\t"<<H_new<<endl;
			mystack.push(op2);
			mywidth.push(W_new);
			myht.push(H_new);
			
	
		}
		
		else
		{
			H_new = h_1 + h_2;
			W_new = max(w_1,w_2);
			mystack.push(op2);
			mywidth.push(W_new);
			myht.push(H_new);
		}  
		
	}
}
cout<<endl;
W_new = float(W_new);
H_new = float(H_new);
float area_me = W_new *H_new;
//cout<<"Area of the entire block is : "<<area_me<<endl;
return area_me ;

}

