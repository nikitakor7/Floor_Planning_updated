/**
This program finds the correct polish expression in the postfix form

author : Nikita Korgaonkar 
*/

#include<iostream>
#include<stack>
#include<string>
#include <typeinfo>
#include<stdlib.h>
#include "generate_polish.h"
#include "generate_polish.cpp"
#include "polish_final.h"
#include "Project_1.h"

using namespace std;


int width =0, height = 0, area_found = 0, val=0;
string postfix;

// Function to convert Infix expression to postfix 
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not. 
bool IsOperand(char C);

string polish_final(int val) 
{
	//int val = atoi(value.c_str());
	cout << val;
	string s;
	s =generate_polish(val);
	//cout <<s<<endl;
	
	postfix = InfixToPostfix(s);
	std :: cout<<"\n"<<"Output = "<<postfix<<"\n";
	return postfix;
	
}
// function to find area
/*int area(int a, int b)
{
	int area_found =  width*height;
	//cout <<"\n" << "Area is"<<area<<endl;
	return area_found;
	
}*/
// Function to evaluate Postfix s and return output
string InfixToPostfix(string s)
{
	// Declaring a Stack from Standard template library in C++. 
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	string k;
	for(int i = 0;i< s.length();i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(s[i] == ' ' || s[i] == ',') continue; 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(s[i])) 
		{
			k = s[i];
			if (k == "+")
			{
				width ++;
				//cout<< width;
			}
				else 
				{
				height++;
				//cout <<height;
			}
		//	val = area(width, height);
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),s[i]))
			{
				
				postfix+= S.top();
			//	cout << postfix;
				S.pop();
			}
			S.push(s[i]);
		}
		// Else if character is an operand
		else if(IsOperand(s[i]))
		{
			postfix +=s[i];
			
		}

		else if (s[i] == '(') 
		{
			S.push(s[i]);
		}

		else if(s[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') 
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit. 
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' )
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = 1; 
	switch(op)
	{
	case '+':
		break;
		
	case '-':
		weight = 1;
		break;

}
	return weight, width, height;
}

// Function to perform an operation and return output. 
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
	
}

