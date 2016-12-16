#include<iostream>
#include<vector>
#include"CutRod.h"
using namespace std;


int main(){

	//¸ÖÌõÇĞ¸îÎÊÌâ
	int n = 10;
	int p[11] = {0,1,5,8,9,10,17,17,20,24,30};
	int rs[22] = {0};
	bottom_up_cut_rod(p,n,rs);

	for(int j=0;j<=n;j++){
		cout<<rs[j]<<"  ";
	}
	cout<<endl;
	for(int j=0;j<=n;j++){
		cout<<rs[n+1+j]<<"  ";
	}

	return 0;
}