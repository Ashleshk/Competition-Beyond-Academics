/************************************************************************************************************************************************/
/*                               Bracket's Mania																								*/
/*			Developed By: Ashlesh Khajbage																										*/	
/*			Created on: 07/09/2018																												*/	
/*																																				*/
/*     Problem Statement:																														*/	
/*	Write a program consisting of a function matched(s) that takes  a string s and checks if the												*/
/*  brackets "(" and ")" in s are matched: that is, every "(" has a matching ")" after it and every ")" has a matching "(" before it.			*/
/*  Your function should ignore all other symbols that appear in s. Your function should return 1 if s has matched brackets and 0 if it			*/
/*  does not and finally print true /false respectively.																						*/	
/*  Input :"(7)(a"																																*/	
/*  Output : False.																																*/
/*  Input :"((jkl)78(A)&l(8(dd(FJI:),):)?)"																										*/
/*  Output :True																																*/
/************************************************************************************************************************************************/
#include<iostream>
using namespace std;
int main()
{
	//variables region
	char s[1000];
	int ctr=0;			 
	//end of variable

	//input String
	cin>>s;

	//length of the string
	int l=strlen(s);
	
	//begin reading character of the String 's'
	for(int i=0;i<l;i++)
	{
		if(s[i]=='(')
			ctr++;
		else if(s[i]==')')
		{
			if (ctr<=0)
			{
				//set false if ctr<=0 i.e the ')' havent appeared
				cout<<"False";
				return 0;
			}
			else
				//we got the closing ')' bracket
				ctr--;
		}
	}
	if (ctr!=0) 
		cout<<"False";
	else
		cout<<"True";
		 
	return 0;
}