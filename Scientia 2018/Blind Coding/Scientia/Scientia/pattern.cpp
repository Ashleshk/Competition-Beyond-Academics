#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j=0,k,t,r;
  
    scanf("%d", &n);
    r=n;
    t=2*n-1;
    k=t;
    int a[t][t];
    for(t=2*n-2;t>=t/2;t--)
    {
    for(i=j;i<=t;i++)
    {
        
    
        a[j][i]=r;
        a[i][j]=r;
        a[t][i]=r;
        a[i][t]=r;
        a[t][t]=r;
    }
    j++;
    r--;
    }

    for(i=0;i<k;i++)
    {
        
    
    
for(j=0;j<k;j++)
{
    printf("%d ",a[i][j]);
    }
        printf("\n");
    }
  
}