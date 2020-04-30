
/************************************************************************************************************************************************/
/*                               ALLIZZWELL																										*/
/*			Developed By: Ashlesh Khajbage																										*/	
/*			Created on: 07/09/2018																												*/	
/*																																				*/
/*     Problem Statement:																														*/
/*																																				*/
/*     Mr.ESP used to tell “ALL IZZ WELL” whenever he gets into any trouble. So his friends and the people around him used to laugh at him. But	*/
/*	 Mr.ESP is very strong in his belief. He believes that the term “ALL IZZ WELL” will make everything fine. Now your task is to ignore the	*/
/*	 story above and find whether there is a path in the given matrix which makes the sentence “ALL IZZ WELL”									*/
/*																																				*/	
/*     There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.									*/
/*																																				*/
/*	Input Specification:																														*/
/*																																				*/
/*     The first line consists of an integer t representing the number of test cases.															*/
/*	 The first line of each test case consists of two integers R and C representing the number of rows and number of columns in the matrix. The */
/*	 description of the matrix follows.																											*/
/*																																				*/
/*	Output Specification:																														*/
/*	For each test case print “YES” if there is a path which makes the sentence “ALLIZZWELL”. Else print “NO”.									*/
/************************************************************************************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
 
#define MAX 101
 
using namespace std;
 
int R, C;
char input[MAX][MAX];
 
int x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, 1, -1, 1, -1};
 
bool visited[MAX][MAX];
char pattern[11] = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
 
bool checkValid(int i, int j){
    if(i>=0 && i<R && j>=0 && j<C)
        return true;
 
    return false;
}
 
string dfs(int i, int j, int pattern_index){
    //cout << "i " << i << " j " << j << " index " << pattern_index << endl;
    string s;
    visited[i][j] = 1;
    if (pattern_index == 9){
        return "YES";
    }
    else{
        for(int x_i=0; x_i<8; x_i++){
            if(checkValid(i+x[x_i], j+y[x_i])){
                if(input[i+x[x_i]][j+y[x_i]] == pattern[pattern_index+1]
                    && !visited[i+x[x_i]][j+y[x_i]]){
 
                    visited[i+x[x_i]][j+y[x_i]] = 1;
                    s = dfs(i+x[x_i], j+y[x_i], pattern_index + 1);
                    if (s == "YES"){
                        return s;
                    visited[i+x[x_i]][j+y[x_i]] = 0;
                    }
                }
            }
        }
    }
    visited[i][j] = 0;
    return "NO";
}
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &R,&C);
 
        memset(visited, 0, sizeof(visited));
 
        for(int i=0; i<R; i++){
                scanf("%s", input[i]);
                //cout << input[i];
        }
 
        int flag = false;
 
        for( int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(input[i][j] == 'A' && dfs(i, j, 0) == "YES"){
                        flag = true;
                        break;
                }
            }
            if(flag)
                break;
        }
 
        if(flag){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
 
    }
    return 0;
}