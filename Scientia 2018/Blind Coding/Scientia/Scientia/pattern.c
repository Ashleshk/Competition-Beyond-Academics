
/************************************************************************************************************************************************/
/*                                Pattern Printing																								*/
/*			Developed By: Ashlesh Khajbage																										*/	
/*			Created on: 07/09/2018																												*/	
/*																																				*/
/*     Problem Statement:																														*/	
/*	In this problem, you need to print the pattern of the following form containing the numbers from  to .										*/		
/*                                                                                                                                              */
/*                            4 4 4 4 4 4 4																										*/
/*                            4 3 3 3 3 3 4																										*/
/*                            4 3 2 2 2 3 4																										*/
/*                            4 3 2 1 2 3 4																										*/
/*                            4 3 2 2 2 3 4																										*/
/*                            4 3 3 3 3 3 4																										*/
/*                            4 4 4 4 4 4 4																										*/
/* 																													                            */
/************************************************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main() 
{
	//varibles
    int n,i,j=0,k,t=0;
  
	//scan the corner value-element
    scanf("%d", &n);
     
    t=2*n-1;
    k=t;
    int a[t][t];
    for(t=2*n-2;t>=t/2;t--)
    {
		for(i=j;i<=t;i++)
		{
			a[j][i]=n;
			a[i][j]=n;
			a[t][i]=n;
			a[i][t]=n;
			a[t][t]=n;
		}
		j++;
		n--;
    }

	//display the matrix
    for(i=0;i<k;i++)
    {
		for(j=0;j<k;j++)
		{
			printf("%d ",a[i][j]);
		}
        printf("\n");
	}
}