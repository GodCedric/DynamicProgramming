#include<iostream>
#include<vector>
#include"LCS.h"

using namespace std;

int main(){

	////////最长公共子序列
	////////最长公共子序列是求两个序列的最长公共子序列
	////////两个序列为x和y
	////////其长度分别为m和n
	////////输出结果即为两序列的最长公共子序列
	cout<<endl;
	cout<<"最长公共子序列问题："<<endl;
	int m3 = 7;
	int n3 = 6;
	char x[7] = {'A','B','C','B','D','A','B'};
	char y[6] = {'B','D','C','A','B','A'};
	cout<<"序列X为：";
	for(int i=0;i<m3;i++)
		cout<<x[i];
	cout<<endl;
	cout<<"序列Y为：";
	for(int i=0;i<n3;i++)
		cout<<y[i];
	cout<<endl;
	int c[8][7] = {0};
	LCS_length(x,y,m3,n3,c);
	cout<<"最长公共子序列长度为：";
	cout<<c[m3][n3]<<endl;
	cout<<"最长公共子序列为：";
	LCS_print(x,y,m3,n3,c);
	cout<<endl;

	return 0;
}