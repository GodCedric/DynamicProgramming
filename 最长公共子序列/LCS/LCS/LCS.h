#ifndef __LCS__H__
#define __LCS__H__
#include<iostream>
using namespace std;

void LCS_length(char x[],char y[],int m,int n,int c[][7]){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
			}else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
			}else{
				c[i][j] = c[i][j-1];
			}
		}
	}
}

void LCS_print(char x[],char y[],int m,int n,int c[][7]){
	if(m==0 || n==0)
		return;
	int center = c[m][n];
	int up = c[m-1][n];
	int left = c[m][n-1];
	int upleft = c[m-1][n-1];
	if(x[m-1]==y[n-1] && center==upleft+1){
		LCS_print(x,y,m-1,n-1,c);
		cout<<x[m-1];
	}else if(x[m-1]!=y[n-1] && left==up){
		LCS_print(x,y,m-1,n,c);//这个和LCS_length里的判断条件对应，当left和up相等时，取得是up，所以这里取up
	}else if(x[m-1]!=y[n-1] && left>up){
		LCS_print(x,y,m,n-1,c);
	}else if(x[m-1]!=y[n-1] && left<up){
		LCS_print(x,y,m-1,n,c);
	}
}



#endif