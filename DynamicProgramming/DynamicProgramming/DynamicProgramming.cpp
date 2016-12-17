#include<iostream>
#include<vector>
#include"CutRod.h"
#include"MatrixChain.h"
using namespace std;


int main(){

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



	
	return 0;
}