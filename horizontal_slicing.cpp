/*
*Horizontal Slicing
*@Author : Nikita Korgaonkar
*
*/

#include<iostream>
#include<vector>
#include<utility>
#include"soft_computation.h"
#include<bits/stdc++.h>

using namespace std;


float compute_horizontal_slicing()
{
	while( i< myVec1.size() && j<myVec2.size())
	{
		myVec3[i].first = myVec2[j].second + myVec1[j].second;
		myVec3[i].second =max( myVec2[j].first, myVec1[j].first);
		if(max(myVec2[j].first> myVec1[i].first)= myVec2[j].first)
			j++;
		if(max(myVec2[j].first < myVec1[i].first)= myVec1[i]].first)
			i++;
	
	}	
	//return myVec3
}


