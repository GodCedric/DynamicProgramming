#include<iostream>
#include<vector>
#include"CutRod.h"
using namespace std;


int main(){

	////////钢条切割问题
	////////钢条切割问题求长度为n的钢条的最佳收益及切割方案
	////////n表示钢条长度，p表示钢条为1~10时的收益值
	////////r为输出，表示钢条长为0~10时，各自的最佳切割收益
	////////s为解，表示长为n的钢条在达到最佳收益时第一段的切割长度
	int n = 10;
	int p[10] = {1,5,8,9,10,17,17,20,24,30};
	int r[11] = {0};
	int s[11] = {0};
	//自底向上的方法
	bottom_up_cut_rod(p,n,r,s);
	//自顶向下的带备忘的方法
	//up_bottom_cut_rod(p,n,r,s);
	//输出结果
	cut_rod_print(n,r,s);
	
	return 0;
}