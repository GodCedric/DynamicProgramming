#ifndef __ACTIVITY__CHOOSE__H__
#define __ACTIVITY__CHOOSE__H__
#include<vector>
#include<iostream>

//动态规划方法解决活动选择问题
void dp_for_ac(vector<int>& s,vector<int>& f,vector<vector<int>>& c,vector<vector<int>>& res){
	int n = s.size()-1;
	for(int i=1;i<=n;i++)
		c[i][i] = 1;
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j = i+l-1;
			c[i][j] = INT_MIN;
			//判断Sij中是否有活动
			int beg = f[i]; //ai的结束时间
			int eend = s[j]; //aj的开始时间
			if(beg >= eend){
				c[i][j] = 0;
			}else{
				int flag = 0; //标志位 标致sij是否为空
				for(int k=i+1;k<j;k++){
					if(s[k]>=beg && f[k]<=eend){
						int t = c[i][k] + c[k][j] + 1;
						if(t>c[i][j]){
							c[i][j] = t;
							res[i][j] = k;
						}
						flag = 1;
					}
				}
				if(flag == 0)
					c[i][j] = 0;
			}
			
		}
	}
}

//动态规划方法输出
void aid_for_print(int i,int j,vector<vector<int>>& c,vector<vector<int>>& res);
void dp_for_ac_print(vector<int>& s,vector<int>& f,int i,int j,vector<vector<int>>& c,vector<vector<int>>& res){
	if(c[i][j]>0 && f[i]<=s[j]){
		cout<<"最大活动个数为："<<c[i][j]+2<<endl;
		cout<<"活动组合为："<<"a"<<i<<" ";
		aid_for_print(i,res[i][j],c,res);
		cout<<"a"<<res[i][j]<<" ";
		aid_for_print(res[i][j],j,c,res);
		cout<<"a"<<j<<endl;
	}else{
		cout<<"最大活动个数为："<<c[i][j]+1<<endl;
		cout<<"活动组合为："<<"a"<<i<<" ";
		aid_for_print(i,res[i][j],c,res);
		cout<<"a"<<res[i][j]<<" ";
		aid_for_print(res[i][j],j,c,res);
	}

}

void aid_for_print(int i,int j,vector<vector<int>>& c,vector<vector<int>>& res){
	if(c[i][j] > 0){
		aid_for_print(i,res[i][j],c,res);
		cout<<"a"<<res[i][j]<<" ";
		aid_for_print(res[i][j],j,c,res);
	}
}

#endif