#include<iostream>
#include"knapsack_problem.h"

using namespace std;

int main(){

	////////�����������⣨̰���㷨��
	cout<<endl;
	cout<<"�����������⣺"<<endl;
	double ww[] = {10,20,30};
	double vv[] = {60,100,120};
	cout<<"��Ӧ��Ʒ������";
	for(int i=0;i<3;i++){
		cout<<ww[i]<<"  ";
	}
	cout<<endl;
	cout<<"��Ӧ��Ʒ�۸�";
	for(int i=0;i<3;i++){
		cout<<vv[i]<<"  ";
	}
	cout<<endl;
	vector<double> w6(ww,ww+3);
	vector<double> v6(vv,vv+3);
	double W = 50;
	cout<<"������������"<<W<<endl;
	double total;
	total = FKP(w6,v6,W);
	cout<<"�������ܳ�����ֵ��"<<total<<endl;
	
	////////0-1�������⣨��̬�滮�㷨��
	cout<<endl;
	cout<<"0-1��������"<<endl;
	cout<<"��Ʒ�������۸�ͬ��"<<endl;
	int n = 3;
	int W2 = 50;
	vector<vector<int>> c6(n+1,vector<int>(W2+1,0));
	zero_one_kp(w6,v6,W2,c6);
	cout<<"�������ܳ�����ֵ��"<<c6[n][W2]<<endl;
	zero_one_kp_print(w6,v6,c6);

	return 0;

}