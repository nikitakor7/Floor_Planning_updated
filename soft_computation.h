#ifndef soft_computation_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define soft_computation_1_H
#include <iostream>
#include<string>
#include <fstream> //Objects belong to this class are associated with files opened for input and output purposes
#include <sstream> //Header providing string stream classes
#include <algorithm>
#include <ctime>
#include <cstdlib> // Header providing standard lib
#include <cmath> // Header providing math functions
#include<vector>

using namespace std;

float soft_computation();

extern vector<pair<float, float> > myVec1;
extern vector<pair<float, float> > myVec2;
extern vector<pair<float, float> > myVec3;

#endif
