
/************************************************************************************************************************************************/
/*                                       Prime-generator																						*/
/*			Developed By: Ashlesh Khajbage																										*/	
/*			Created on: 07/09/2018																												*/	
/*																																				*/
/*			 Problem Statement:																													*/
/*				Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between	*/
/*				two given numbers!																												*/
/*			 Input:																																*/
/*				The input begins with the number t of test cases in a single line (t<=10).														*/
/*				In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.		*/
/*																																				*/
/*			Output:																																*/
/*			For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.	*/
/************************************************************************************************************************************************/
#include<iostream>
using namespace std;

int checkprime(int n) {
	int i;
	if(n == 1 || n == 0)
		return 0;
	for(i=2; i*i<=n; i++) {
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int m, n;
		cin>>m>>n;
		int i;
		for(i=m; i<=n; i++) {
			int k;
			k = checkprime(i);
			if(k)
				cout<<i<<endl;
		}
		cout<<endl;
	}
	return 0;
}