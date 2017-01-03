#include<iostream>
#include"activity_choose.h"

int main(){

	////////活动选择问题
	////使用动态规划算法////
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
	////使用贪心算法////
	//递归版
	vector<int> result;
	recursive_activity_selector(s5,f5,0,11,result);
	recursive_activity_selector_print(result);
	//迭代版
	cout<<endl;
	recursive_activity_selector2(s5,f5);
	cout<<endl;

	return 0;
}