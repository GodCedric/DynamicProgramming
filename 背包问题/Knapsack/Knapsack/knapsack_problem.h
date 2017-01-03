#ifndef __FRACKTIONAL__KNAPSACK__PROBLEM__
#define __FRACKTIONAL__KNAPSACK__PROBLEM__
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//分数背包问题（贪心算法）
double FKP(vector<double>& w,vector<double>& v,double& W){
	int n = w.size();
	vector<double> vpw(n);
	unordered_map<double,double> mp;
	double curW = 0;
	double total = 0;
	for(int i=0;i<n;i++){
		vpw[i] = v[i]/w[i];
		mp[vpw[i]] = w[i];
	}
	sort(vpw.begin(),vpw.end(),greater<double>());
	vector<double>::iterator itr = vpw.begin();
	for(itr;itr!=vpw.end();itr++){
		if((curW+mp[*itr]) <= W){
			total += (*itr)*mp[*itr];
			curW += mp[*itr];
		}else{
			total += (W-curW)*(*itr);
		}
	}
	return total;
}


//0-1背包问题（动态规划算法）
void zero_one_kp(vector<double>& w,vector<double>& v,int& W,vector<vector<int>>& c){
	int n = w.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(w[i-1] > j){
				c[i][j] = c[i-1][j];
			}else{
				//包含vi
				int t1 = c[i-1][j-w[i-1]] + v[i-1];
				//不包含vi
				int t2 = c[i-1][j];
				c[i][j] = (t1>t2)?t1:t2;
			}
		}
	}
}

void zero_one_kp_print(vector<double>& w,vector<double>& v,vector<vector<int>>& c){
	int n = c.size() - 1;
	int j = c[0].size() - 1;
	vector<int> result(n+1);
	cout<<"背包所装的物品为：";
	for(int i=n;i>=1;i--){
		if(c[i][j] > c[i-1][j]){
			result[i] = 1;
			j -= w[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		if(result[i])
			cout<<i<<" ";
	}
	cout<<endl;
}



#endif
