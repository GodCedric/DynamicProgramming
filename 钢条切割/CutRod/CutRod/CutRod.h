#ifndef __CUTROD__H__
#define __CUTROD__H__
#include<iostream>
using namespace std;

//�Ե����ϵķ���
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

//�Զ����µķ���
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

//���
void cut_rod_print(int n,int r[],int s[]){
	cout<<"�����и����⣺"<<endl;
	cout<<"����Ϊ0��"<<n<<"ʱ��������棺";
	for(int j=1;j<=n;j++){
		cout<<r[j]<<"  ";
	}
	cout<<endl;
	cout<<"��������Ӧ�ĵ�һ���и�ȣ�";
	for(int j=1;j<=n;j++){
		cout<<s[j]<<"  ";
	}
	cout<<endl;

	cout<<"n="<<n<<"ʱ������и�����Ϊ��"<<r[n]<<"  �и��Ϊ��";
	while(s[n]){
		cout<<s[n]<<" ";
		n = n-s[n];
	}
	cout<<endl;
}


#endif