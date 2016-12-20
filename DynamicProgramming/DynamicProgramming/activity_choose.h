#ifndef __ACTIVITY__CHOOSE__H__
#define __ACTIVITY__CHOOSE__H__
#include<vector>
#include<iostream>

//��̬�滮��������ѡ������
void dp_for_ac(vector<int>& s,vector<int>& f,vector<vector<int>>& c,vector<vector<int>>& res){
	int n = s.size()-1;
	for(int i=1;i<=n;i++)
		c[i][i] = 1;
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j = i+l-1;
			c[i][j] = INT_MIN;
			//�ж�Sij���Ƿ��л
			int beg = f[i]; //ai�Ľ���ʱ��
			int eend = s[j]; //aj�Ŀ�ʼʱ��
			if(beg >= eend){
				c[i][j] = 0;
			}else{
				int flag = 0; //��־λ ����sij�Ƿ�Ϊ��
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

//��̬�滮�������
void aid_for_print(int i,int j,vector<vector<int>>& c,vector<vector<int>>& res);
void dp_for_ac_print(vector<int>& s,vector<int>& f,int i,int j,vector<vector<int>>& c,vector<vector<int>>& res){
	if(c[i][j]>0 && f[i]<=s[j]){
		cout<<"�������Ϊ��"<<c[i][j]+2<<endl;
		cout<<"����Ϊ��"<<"a"<<i<<" ";
		aid_for_print(i,res[i][j],c,res);
		cout<<"a"<<res[i][j]<<" ";
		aid_for_print(res[i][j],j,c,res);
		cout<<"a"<<j<<endl;
	}else{
		cout<<"�������Ϊ��"<<c[i][j]+1<<endl;
		cout<<"����Ϊ��"<<"a"<<i<<" ";
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