#include<iostream>
#include<vector>
#include"CutRod.h"
using namespace std;


int main(){

	////////�����и�����
	////////�����и������󳤶�Ϊn�ĸ�����������漰�и��
	////////n��ʾ�������ȣ�p��ʾ����Ϊ1~10ʱ������ֵ
	////////rΪ�������ʾ������Ϊ0~10ʱ�����Ե�����и�����
	////////sΪ�⣬��ʾ��Ϊn�ĸ����ڴﵽ�������ʱ��һ�ε��и��
	int n = 10;
	int p[10] = {1,5,8,9,10,17,17,20,24,30};
	int r[11] = {0};
	int s[11] = {0};
	//�Ե����ϵķ���
	bottom_up_cut_rod(p,n,r,s);
	//�Զ����µĴ������ķ���
	//up_bottom_cut_rod(p,n,r,s);
	//������
	cut_rod_print(n,r,s);
	
	return 0;
}