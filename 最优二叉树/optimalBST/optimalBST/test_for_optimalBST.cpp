#include<iostream>
#include"optimalBST.h"

int main(){
	
	////////最优二叉树问题
	cout<<endl;
	cout<<"最优二叉树问题："<<endl;
	int n4 = 6;
	double p[6] = {0,0.15,0.10,0.05,0.10,0.20};
	double q[6] = {0.05,0.10,0.05,0.05,0.05,0.10};
	cout<<"搜索概率：";
	for(int i=1;i<n4;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	cout<<"伪搜索概率：";
	for(int i=0;i<n4;i++)
		cout<<q[i]<<" ";
	cout<<endl;
	vector<double> p4(p,p+n4);
	vector<double> q4(q,q+n4);
	vector<vector<double>> e4(n4+1,vector<double>(n4+1,0));
	vector<vector<double>> w4(n4+1,vector<double>(n4+1,0));
	vector<vector<int>> root(n4,vector<int>(n4,0));
	optimal_bst(p4,q4,e4,w4,root);
	cout<<"最优二叉搜索树期望代价：";
	cout<<e4[1][n4-1]<<endl;
	cout<<"最优二叉搜索树为："<<endl;
	optimalBST_print(root,1,5);

	return 0;
}