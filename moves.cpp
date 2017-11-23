/*
*
*This file generates moves for simulated annealing
*generate moves for the entered polish expression
*move 1 : exchange of operand
*move 2 : exchange of operator
*move 3 : exchange of operand and operator
*
*/
#include<iostream>
#include<string>
#include<ctime>
#include"polish_final.h"
#include <vector>
#include <random>
#include<stack>
#include <algorithm>
//#include <iterator>
#include"moves.h"
//#include "legal2.h"
//#include"generate_polish.h"
//#include"polish_final.h"
using namespace std;

string funny;
string moves(string);
string temp, test;

//stack <int> mystack;
string move1(string test, int find)
{
// Exchange two operands that have no other operands in between
	char swap;
	cout<< test;
	int i, j;
	//i = find;
	cout << "find" << find<<endl;
	for(i=find;i<test.length();i++)
	{
		if(isdigit(test[i]))
		{
			//char r =  test[i];
			for(j=i+1; j<test.length(); j++)
			{
				if(isdigit(test[j]))
				{
				swap = test[i];
				test[i] =test[j];
				test[j] = swap;
				break;
				}
			}
			break;
		}
		else
		{
			find = find+1;
			if(find< test.length()-1)
			{
				move1(test, find);
			}
			else
			moves(test);
		}
	}
	cout<< "\n"<< test;
	return test;	
	

		}


string move2(string test, int find, int find2)
{	
// Complement a series of operators between two operands
char swap;
	cout<< test;
	int i, j, count;
	cout<<endl;
	cout << "find" << find<<"\t"<<find2<<endl;
	for(i=find; i< find2; i++)
	{
		if(!isdigit(test[i]))
		{
			if(test[i] == '+')
			{
				test[i] ='-';		
			}
					else
					test[i] = '+';
					
					count++;
			}
	}
				if(count ==0)
				{
					
					int k = test.length()-1;
					for( int j = k; j>0; j--)
					{
						if(isdigit(test[j]))
						break;
						else
						{						
							if(test[j] == '+')
							{
								test[j] ='-';
							}
							else
							test[j] = '+';
						}
					}
				
				}
	cout<< "\n"<< test;
	return test;	
				}
				
bool legal(string test)
{
	//This function checks if the string is legal
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag = false;
	int operand, oprator;
	//condition 1 : check if the first digit is an operator
		if(!isdigit(test[0]))
		{
			flag1 = true;
		}
		if(!isdigit(test[1]))
		{
			flag1 = true;
		}
/*******************************************************************************************************/
short int count1 = 0, count2;
//bool flag1 , flag2;
stack<char>stack_new;

cout <<"ip to legal part 2  "<< test<<endl;
		for(int i =0 ; i< test.length(); i++)
		{
			if(isdigit(test[i]))
			{
				stack_new.push(test[i]);
				//cout << "new_val in stack" << (test[i])<<"\t";
				count1 ++;
			}
			else
			{
				unsigned int op1, op2;
				if(!stack_new.empty())
				{
				
					op1 = stack_new.top();
					//cout << "op1"<<op1 <<"\t";
					stack_new.pop();
					count1 --;
					
					if(!stack_new.empty())
					{
					op2 = stack_new.top();
					stack_new.pop();
					count1 --;
					//cout << "op2"<< op2 <<"\t";
						
					}
					else 
					{
						flag2 = true;
						break;
					}
					
					
					stack_new.push(op1 = op1 + op2);
				//	cout << "op1+op2"<<op1+op2 <<"\t";
					count1 ++;
					
				}
				else
				{
					flag2 = true;
					break;
				}
			}
			
			
		
			}
			if(count1 !=1)
			{
				flag2 = true;
			}
			cout << count1;
			cout << flag2 ;
			

			
/*****************************************************************************************************************/			
	//condition 3 : check if two same operators are adjacent	
		for(int i =0; i< test.length()-1; i++)
		{
			if(!isdigit(test[i]))
			{
				if(!isdigit(test[i+1]))
				{
					if(test[i+1] == test[i])
					{
						flag3 =true;
						//return flag3;
						break;
					}
				}
			}
		}
		
//check if the string is legal considering all 3 moves		
	 flag = flag1 or flag2 or flag3;
	cout << "your flag value is :"<<flag <<"|"<<flag2;
	return flag;		
}
string move3(string test, int find)
{
//Exchange adjacent operand and operator if the resulting expression still a normalized Polish exp

	char swap;
	cout<< test<<endl;
	 temp = test;
	 cout << "find"<<find<<endl; // generating a random number to start
			int i = find;
				if(!isdigit(test[i])) //check if its an operator
					{
						int j = i+1, r = i-1; //going toward the right and checking
							if(isdigit(test[j]))
								{
								swap = temp[i]; //check if its an operand
								temp[i]=temp[j];
								temp[j] = swap;
								}
							else
								{
									cout<<"left"<<r<<endl; //going towards the left and checking
									if(isdigit(test[r])) //checking for operand
										{
											swap = temp[i]; 
											temp[i]=temp[r];
											temp[r] = swap;	
										}
						
								}
							bool k = legal(temp);
							cout<<"value of flag  "<<k<<endl;
										if(k == true)
											{
												cout<<"in loop";
												int a =0;
												while( a <5)  //retrying move 3 for a different initial value
													{
														temp = test;
														find = rand()%test.length();
														a++;
														move3(temp, find);
														bool b = legal(temp);
														cout<<"value of flag  "<<b<<endl;
															if(b == false)
																{
																	cout<<"in 2nd loop" << endl;
																	test = temp;
																	break;
																}
															else
																{
																	cout<<"in 3rd loop" << endl;
																	move(test);
																	break;
																}
																	
														}
												}
											else
												test = temp;
			}		
		 else if(isdigit(test[i]))
			{
					int j = i+1; int r = i-1;
					if(!isdigit(test[j]))
					{
						swap = temp[i]; //checking right
						temp[i]=temp[j];
						temp[j] = swap;
					}
						//bool k = legal(temp);}
						else
						{
							if(!isdigit(test[r]))
								{
									swap = temp[i]; //checking left
									temp[i]=temp[r];
									temp[r] = swap;
								}
						}
						bool k = legal(temp); // doing legal analysis
						cout<<"value of flag  "<<k<<endl;
								if(k== true)
									{
										int a =0;
										while( a <5)
											{
												temp = test;
												find = rand()%test.length();
												move3(temp,  find);
												a++;
												bool b = legal(temp);
															if(b == false)
																{
																	test = temp;
																	break;
																}
															else
															moves(test);
															break;
											}
									}
								else
									test = temp;
					}
					else
					{
						find = rand()%test.length();
						move3(temp,  find);
							bool b = legal(temp);
										if(b == false)
												{
													test = temp;
													//break;
												}
										else
										moves(test);
					}
	cout<<"new expression"<<temp << endl;
					

	return test;
		}
			
string moves(string godhelpme)
{
	int i =2, flag =0;
	vector <char> g1;
	vector <int> g2;
	int n;
    int move_choice =rand()%2+1;// + 1;
    bool move_3 = rand()%2;
    int find = rand()% godhelpme.length();
    int find2 =rand()% godhelpme.length();
   while( find == find2)
   {
   	 find =  rand()% godhelpme.length();
   	 find2 = rand()% godhelpme.length();
   	 
   }
	if(find2 < find)
	{
		swap(find2,find);
	}
    cout << "\n"<<move_3;
    cout <<"move_choice"<< move_choice<<endl; 
	string test = godhelpme;
	string temp = test;
	
  switch(move_choice)
  {
  	case 1:
  		funny = move1(temp, find);
  		temp = funny;
  		break;
  	
	case 2:
	  	funny = move2(temp,find, find2);
	  	temp = funny;
	  break;
	  
	 case 3:
	 	funny = move3(temp,find);
	 	temp = funny;
	 	break; 	
  }
  return funny;
}
   

