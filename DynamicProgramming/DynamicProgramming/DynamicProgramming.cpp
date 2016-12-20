#include<iostream>
#include<vector>
#include"CutRod.h"
#include"MatrixChain.h"
#include"LCS.h"
#include"optimalBST.h"
#include"activity_choose.h"
using namespace std;


int main(){

	/*************动态规划*************/
	
	////////钢条切割问题
	////////钢条切割问题求长度为n的钢条的最佳收益及切割方案
	////////n表示钢条长度，p表示钢条为1~10时的收益值
	////////r为输出，表示钢条长为0~10时，各自的最佳切割收益
	////////s为解，表示长为n的钢条在达到最佳收益时第一段的切割长度
	int n1 = 10;
	int p1[10] = {1,5,8,9,10,17,17,20,24,30};
	int r1[11] = {0};
	int s1[11] = {0};
	//自底向上的方法
	bottom_up_cut_rod(p1,n1,r1,s1);
	//自顶向下的带备忘的方法
	//up_bottom_cut_rod(p,n,r,s);
	//输出结果
	cut_rod_print(n1,r1,s1);


	////////矩阵链乘法问题
	////////矩阵链乘法问题是求1~n个矩阵相乘的最小代价问题
	////////n表示矩阵长度
	////////p表示矩阵阶数
	////////m为最优代价，其下标为i,j,m[i][j]表示了Ai~Aj矩阵的最低代价
	////////s为最优解，其下标为i,j,s[i][j]表示了在改位置处画分割括号，则Ai~Aj的乘法将达到最低代价
	cout<<endl;
	cout<<"矩阵乘法问题："<<endl;
	int n2 = 6;						   //6个矩阵
	int p2[7] = {30,35,15,5,10,20,25};  //矩阵阶数，共6个矩阵相乘
	int m2[7][7] = {0};                 //最优代价
	int s2[7][7] = {0};                 //最优解
	//自底向上的方法
	matirx_chain_order(p2,n2,m2,s2);
	cout<<"6个矩阵相乘的最低代价为：";
	cout<<m2[1][6]<<endl;
	cout<<"最优括号化方案为：";
	matrix_chian_print(s2,1,6);
	cout<<endl;


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

	//最优二叉树问题
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

	
	/*************贪心算法*************/
	
	//活动选择问题
	cout<<endl;
	cout<<"活动选择问题："<<endl;
	int n5 = 12;
	int ss[] = {0,1,3,0,5,3,5,6,8,8,2,12};
	int ff[] = {0,4,5,6,7,9,9,10,11,12,14,16}; //默认结束时间已经按递增顺序排列好
	vector<int> s5(ss,ss+12);
	vector<int> f5(ff,ff+12);
	vector<vector<int>> c5(n5,vector<int>(n5,0));
	vector<vector<int>> res5(n5,vector<int>(n5,0));
	dp_for_ac(s5,f5,c5,res5);
	dp_for_ac_print(s5,f5,1,11,c5,res5);


	
	return 0;
}