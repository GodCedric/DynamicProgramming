#ifndef __CUTROD__H__
#define __CUTROD__H__
#include<iostream>
using namespace std;

//自底向上的方法
void bottom_up_cut_rod(int p[],int n,int r[],int s[]){
	for(int j=1;j<=n;j++){
		int q = INT_MIN;
		for(int i=1;i<=j;i++){
			if(q < p[i-1]+r[j-i]){
				q = p[i-1]+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
}

//自顶向下的方法
int memoized_cut_rod_aux(int p[],int n,int r[],int s[]){
	int q;
	if(r[n]>=0)
		return r[n];
	if(n==0)
		q = 0;
	else{
		q = INT_MIN;
		for(int i=1;i<=n;i++){
			if(q < p[i-1]+memoized_cut_rod_aux(p,n-i,r,s)){
				q = p[i-1]+memoized_cut_rod_aux(p,n-i,r,s);
				s[n] = i;
			}
		}
		r[n] = q;
	}
	return q;
}


void up_bottom_cut_rod(int p[],int n,int r[],int s[]){
	for(int i=0;i<=n;i++)
		r[i] = INT_MIN;
	memoized_cut_rod_aux(p,n,r,s);
}

//输出
void cut_rod_print(int n,int r[],int s[]){
	cout<<"钢条切割问题："<<endl;
	cout<<"长度为0到"<<n<<"时的最佳收益：";
	for(int j=1;j<=n;j++){
		cout<<r[j]<<"  ";
	}
	cout<<endl;
	cout<<"最佳收益对应的第一段切割长度：";
	for(int j=1;j<=n;j++){
		cout<<s[j]<<"  ";
	}
	cout<<endl;

	cout<<"n="<<n<<"时，最大切割收益为："<<r[n]<<"  切割方案为：";
	while(s[n]){
		cout<<s[n]<<" ";
		n = n-s[n];
	}
	cout<<endl;
}


#endif