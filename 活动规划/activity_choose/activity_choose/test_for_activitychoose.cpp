#include<iostream>
#include"activity_choose.h"

int main(){

	////////�ѡ������
	////ʹ�ö�̬�滮�㷨////
	cout<<endl;
	cout<<"�ѡ�����⣺"<<endl;
	int n5 = 12;
	int ss[] = {0,1,3,0,5,3,5,6,8,8,2,12};
	int ff[] = {0,4,5,6,7,9,9,10,11,12,14,16}; //Ĭ�Ͻ���ʱ���Ѿ�������˳�����к�
	vector<int> s5(ss,ss+12);
	vector<int> f5(ff,ff+12);
	vector<vector<int>> c5(n5,vector<int>(n5,0));
	vector<vector<int>> res5(n5,vector<int>(n5,0));
	dp_for_ac(s5,f5,c5,res5);
	dp_for_ac_print(s5,f5,1,11,c5,res5);
	////ʹ��̰���㷨////
	//�ݹ��
	vector<int> result;
	recursive_activity_selector(s5,f5,0,11,result);
	recursive_activity_selector_print(result);
	//������
	cout<<endl;
	recursive_activity_selector2(s5,f5);
	cout<<endl;

	return 0;
}