#include<iostream>
#include<vector>
#include"MatrixChain.h"

using namespace std;

int main(){
	
	////////�������˷�����
	////////�������˷���������1~n��������˵���С��������
	////////n��ʾ���󳤶�
	////////p��ʾ�������
	////////mΪ���Ŵ��ۣ����±�Ϊi,j,m[i][j]��ʾ��Ai~Aj�������ʹ���
	////////sΪ���Ž⣬���±�Ϊi,j,s[i][j]��ʾ���ڸ�λ�ô����ָ����ţ���Ai~Aj�ĳ˷����ﵽ��ʹ���
	cout<<endl;
	cout<<"����˷����⣺"<<endl;
	int n2 = 6;						   //6������
	int p2[7] = {30,35,15,5,10,20,25};  //�����������6���������
	int m2[7][7] = {0};                 //���Ŵ���
	int s2[7][7] = {0};                 //���Ž�
	//�Ե����ϵķ���
	matirx_chain_order(p2,n2,m2,s2);
	cout<<"6��������˵���ʹ���Ϊ��";
	cout<<m2[1][6]<<endl;
	cout<<"�������Ż�����Ϊ��";
	matrix_chian_print(s2,1,6);
	cout<<endl;

	return 0;
}