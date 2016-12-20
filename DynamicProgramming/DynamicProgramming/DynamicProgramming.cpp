#include<iostream>
#include<vector>
#include"CutRod.h"
#include"MatrixChain.h"
#include"LCS.h"
#include"optimalBST.h"
#include"activity_choose.h"
using namespace std;


int main(){

	/*************��̬�滮*************/
	
	////////�����и�����
	////////�����и������󳤶�Ϊn�ĸ�����������漰�и��
	////////n��ʾ�������ȣ�p��ʾ����Ϊ1~10ʱ������ֵ
	////////rΪ�������ʾ������Ϊ0~10ʱ�����Ե�����и�����
	////////sΪ�⣬��ʾ��Ϊn�ĸ����ڴﵽ�������ʱ��һ�ε��и��
	int n1 = 10;
	int p1[10] = {1,5,8,9,10,17,17,20,24,30};
	int r1[11] = {0};
	int s1[11] = {0};
	//�Ե����ϵķ���
	bottom_up_cut_rod(p1,n1,r1,s1);
	//�Զ����µĴ������ķ���
	//up_bottom_cut_rod(p,n,r,s);
	//������
	cut_rod_print(n1,r1,s1);


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


	////////�����������
	////////����������������������е������������
	////////��������Ϊx��y
	////////�䳤�ȷֱ�Ϊm��n
	////////��������Ϊ�����е������������
	cout<<endl;
	cout<<"��������������⣺"<<endl;
	int m3 = 7;
	int n3 = 6;
	char x[7] = {'A','B','C','B','D','A','B'};
	char y[6] = {'B','D','C','A','B','A'};
	cout<<"����XΪ��";
	for(int i=0;i<m3;i++)
		cout<<x[i];
	cout<<endl;
	cout<<"����YΪ��";
	for(int i=0;i<n3;i++)
		cout<<y[i];
	cout<<endl;
	int c[8][7] = {0};
	LCS_length(x,y,m3,n3,c);
	cout<<"����������г���Ϊ��";
	cout<<c[m3][n3]<<endl;
	cout<<"�����������Ϊ��";
	LCS_print(x,y,m3,n3,c);
	cout<<endl;

	//���Ŷ���������
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

	
	/*************̰���㷨*************/
	
	//�ѡ������
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


	
	return 0;
}