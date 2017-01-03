#include<iostream>
#include"knapsack_problem.h"

using namespace std;

int main(){

	////////分数背包问题（贪心算法）
	cout<<endl;
	cout<<"分数背包问题："<<endl;
	double ww[] = {10,20,30};
	double vv[] = {60,100,120};
	cout<<"对应商品重量：";
	for(int i=0;i<3;i++){
		cout<<ww[i]<<"  ";
	}
	cout<<endl;
	cout<<"对应商品价格：";
	for(int i=0;i<3;i++){
		cout<<vv[i]<<"  ";
	}
	cout<<endl;
	vector<double> w6(ww,ww+3);
	vector<double> v6(vv,vv+3);
	double W = 50;
	cout<<"背包承载量："<<W<<endl;
	double total;
	total = FKP(w6,v6,W);
	cout<<"背包所能承最大价值："<<total<<endl;
	
	////////0-1背包问题（动态规划算法）
	cout<<endl;
	cout<<"0-1背包问题"<<endl;
	cout<<"商品重量及价格同上"<<endl;
	int n = 3;
	int W2 = 50;
	vector<vector<int>> c6(n+1,vector<int>(W2+1,0));
	zero_one_kp(w6,v6,W2,c6);
	cout<<"背包所能承最大价值："<<c6[n][W2]<<endl;
	zero_one_kp_print(w6,v6,c6);

	return 0;

}