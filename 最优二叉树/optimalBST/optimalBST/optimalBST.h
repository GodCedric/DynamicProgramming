#ifndef __OPTIMALBST__H__
#define __OPTIMALBST__H__
#include<vector>
using namespace std;

void optimal_bst(vector<double>& p,vector<double>& q,vector<vector<double>>& e,vector<vector<double>>& w,vector<vector<int>>& root){
	int n = p.size()-1;
	for(int i=1;i<=n+1;i++){
		e[i][i-1] = q[i-1];
		w[i][i-1] = q[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j = i+l-1;
			e[i][j] = DBL_MAX;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for(int r=i;r<=j;r++){
				double t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t < e[i][j]){
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
}

void optimalBST_print(vector<vector<int>>& root,int i,int j){
	if(j-i > 0){
		cout<<"结点k"<<root[i][j]<<"：";
		if(root[i][j] > i && root[i][j] < j){
			cout<<"左孩子为k"<<root[i][root[i][j]-1]<<",";
			cout<<"右孩子为k"<<root[root[i][j]+1][j]<<"；"<<endl;
			optimalBST_print(root,i,root[i][j]-1);
			optimalBST_print(root,root[i][j]+1,j);
		}else if(root[i][j] == i && root[i][j]+1 < j){
			cout<<"左孩子为d"<<i-1<<",";
			cout<<"右孩子为k"<<root[root[i][j]+1][j]<<"；"<<endl;
			optimalBST_print(root,root[i][j]+1,j);
		}else if(root[i][j] > i && root[i][j] == j){
			cout<<"左孩子为k"<<root[i][root[i][j]-1]<<",";
			cout<<"右孩子为d"<<j<<"；"<<endl;
			optimalBST_print(root,i,root[i][j]-1);
		}
	}else if(j-i == 0){
		cout<<"结点k"<<root[i][j]<<"：";
		cout<<"左孩子为d"<<i-1<<",";
		cout<<"右孩子为d"<<i<<"；"<<endl;
	}
	return;
}

#endif