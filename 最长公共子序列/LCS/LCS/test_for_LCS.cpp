#include<iostream>
#include<vector>
#include"LCS.h"

using namespace std;

int main(){

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

	return 0;
}