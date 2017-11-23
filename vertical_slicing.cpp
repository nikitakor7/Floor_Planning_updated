/*
* Vertical Slicing
*@Author : Nikita Korgaonkar
*/

#include<iostream>
#include<vector>
#include<utility>
#include"soft_computation.h"
#include<bits/stdc++.h>

using namespace std;


float compute_vertical_slicing()
{
	while( i< myVec1.size() && j<myVec2.size())
	{
		myVec3[i].first = myVec2[j].first + myVec1[j].first;
		myVec3[i].second = myVec2[j].second + myVec1[j].second;
		if(max(myVec2[j].second > myVec1[i].second)= myVec2[j].second)
			j++;
		if(max(myVec2[j].second < myVec1[i].second)= myVec1[i]].second)
			i++;
	
	}	
	return myVec3
}


