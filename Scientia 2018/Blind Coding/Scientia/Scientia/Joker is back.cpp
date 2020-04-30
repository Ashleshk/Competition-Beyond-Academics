
/************************************************************************************************************************************************/
/*                                JOKER-IS-BACK - Knifes Are Fun																				*/
/*			Developed By: Ashlesh Khajbage																										*/	
/*			Created on: 07/09/2018																												*/	
/*																																				*/
/*     Problem Statement:																														*/	
/*	Joker has many knifes, and he wants to assign a distinct integer to each knife so he can easily identify them. The i-th knife can have an	*/
/*	integer between 1 and maxNumber[i], inclusive.Return the number of ways he can assign numbers to his knifes, modulo 1,000,000,007.			*/
/*	 If it's impossible to assign distinct integers to the knifes, print 0.																		*/						
/*                                                                                                                                              */
/*                            																										            */
/*    Input:																																	*/ 
/*			The first line contains the number of test cases T (1 <= T <= 666)																	*/
/*																																				*/
/* 			Each test case has 2 lines - 1st line denotes number of knifes N (1 <= N <= 66) Joker has and the 2nd line denotes the numbers		*/
/*			{maxNumber[0]....maxNumber[N-1]} Joker has.1 <= maxNumber[i] <= 3000																*/
/*																																				*/
/*	Output																																		*/
/*			Print the number of ways Joker can assign numbers to his knifes, modulo 1,000,000,007.												*/
/*			If it's impossible to assign distinct integers to the knifes, print 0. In last line print											*/
/*			the string "KILL BATMAN". Don't print any extra spaces.                         													*/													*/
/*                             																													*/
/*  																													                        */
/************************************************************************************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>

#define MAX 67
#define ll long long
#define MOD 1000000007
using namespace std;

int maxN[MAX];

int main(){
    int t;
    int N;
    ll ans ;
    cin >> t;
    while (t--){
        ans = 1;
        scanf("%d",&N);
        for (int i=0; i<N; i++){
            scanf("%d",&maxN[i]);
        }
        sort(maxN, maxN + N);
        for (int i=0; i<N; i++){
            ans = (ans * (maxN[i]-i))%MOD;
        }
        cout << ans << endl;
    }
    cout << "KILL BATMAN\n";
    return 0;
}