#ifndef __MATRIXCHAIN__H__
#define __MATRIXCHAIN__H__
#include<iostream>
using namespace std;

void matirx_chain_order(int p[],int n,int m[][7],int s[][7]){
	for(int l=2;l<=n;l++){
		int j,q;
		for(int i=1;i<=n-l+1;i++){
			j = i+l-1;
			m[i][j] = INT_MAX;
			for(int k=i;k<j;k++){
				q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void matrix_chian_print(int s[][7],int i,int j){
	if(i == j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		matrix_chian_print(s,i,s[i][j]);
		matrix_chian_print(s,s[i][j]+1,j);
		cout<<")";
	}
}

#endif