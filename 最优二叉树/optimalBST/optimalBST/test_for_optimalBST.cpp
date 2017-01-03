#include<iostream>
#include"optimalBST.h"

int main(){
	
	////////���Ŷ���������
	cout<<endl;
	cout<<"���Ŷ��������⣺"<<endl;
	int n4 = 6;
	double p[6] = {0,0.15,0.10,0.05,0.10,0.20};
	double q[6] = {0.05,0.10,0.05,0.05,0.05,0.10};
	cout<<"�������ʣ�";
	for(int i=1;i<n4;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	cout<<"α�������ʣ�";
	for(int i=0;i<n4;i++)
		cout<<q[i]<<" ";
	cout<<endl;
	vector<double> p4(p,p+n4);
	vector<double> q4(q,q+n4);
	vector<vector<double>> e4(n4+1,vector<double>(n4+1,0));
	vector<vector<double>> w4(n4+1,vector<double>(n4+1,0));
	vector<vector<int>> root(n4,vector<int>(n4,0));
	optimal_bst(p4,q4,e4,w4,root);
	cout<<"���Ŷ����������������ۣ�";
	cout<<e4[1][n4-1]<<endl;
	cout<<"���Ŷ���������Ϊ��"<<endl;
	optimalBST_print(root,1,5);

	return 0;
}