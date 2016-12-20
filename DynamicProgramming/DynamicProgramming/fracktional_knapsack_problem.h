#ifndef __FRACKTIONAL__KNAPSACK__PROBLEM__
#define __FRACKTIONAL__KNAPSACK__PROBLEM__
#include<vector>
#include<algorithm>
#include<unordered_map>

double FKP(vector<double> w,vector<double> v,double W){
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


#endif
