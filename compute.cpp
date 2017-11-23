/***Find pairs*/

#include<iostream>
#include<vector>
#include<utility>
#include"soft_computation.cpp"

using namespace std;


float compute_vertical_slicing(vector myVec1, vector myVec2, vector myVec3)
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


