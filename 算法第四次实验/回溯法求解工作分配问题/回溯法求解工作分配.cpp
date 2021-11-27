#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include <bits/stdc++.h>
#define MAXN 30            
using namespace std;
int n , min_sum_cost;//��¼���˹����������ܷ���
int costs[MAXN][MAXN];//��¼������i�������j��������ķ��ã���Ϊcosts[i][j]
int visited[MAXN];//visited[i]���ڼ�¼����i�Ƿ��Ѿ������乤����0��ʾδ���䣬1��ʾ�ѷ���
int arrange[MAXN];//��¼��ǰ�������
int bestArrange[MAXN];//��¼���Ű������

//���ļ��ж�ȡ���ݲ����������̨
void readFile (int d)
{
	FILE*f;
	if(d==3)
	f = fopen ( "1.txt","r" );
	else if(d==10)
	f = fopen ( "10.txt","r" );
	else if(d==20)
	f = fopen ( "20.txt","r" );
	if (f==NULL)
	{
		printf ( "��ȡ�ļ�����" );
		return;
	}
	fscanf (f,"%d" , &n );
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fscanf(f, "%d" , &costs[i][j] );
	}
	printf ( "%d����ֱ�����%d�����˵Ĺ���������ϸΪ:\n",n,n );
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf ( "%d," , costs[i][j] );
		}
		printf ( "\n" );
	}
	fclose ( f );
}

//���ݷ�����С�ܷ���
void getMinSumCost ( int i , int sum )// i��ʾ��ǰ���ڷ���Ĺ�����sum��ʾ����
{
	if (sum > min_sum_cost) //�����ǰ�����Ѿ�������֪����С���ѣ����֦ 
		return;
	if (i == n + 1 && sum < min_sum_cost)//���������еĹ������ؽ��
	{
		min_sum_cost = sum;
		memcpy ( bestArrange , arrange , sizeof ( arrange ) );
		return;
	}

	for (int j = 1; j <= n; j++)//Ϊ��1����n���˷��乤��
	{
		if (!visited[j]) //�������jδ�����乤��
		{
			visited[j] = 1;//�����Ϊ�ѷ���״̬
			arrange[i] = j;//��ʾ����i���������j
			getMinSumCost ( i + 1 , sum+ costs[i][j] );//�ݹ�����i+1������
			visited[j] = 0;//����
		}
	}
}

//����������ļ�output.txt�����������̨
void writeFile (int d )
{
	printf ( "��С�ܻ���Ϊ��%d\n" , min_sum_cost );
	for (int i = 1; i <= n; i++)
	{
		printf ( "����%d���������%d,����Ϊ%d\n" , i , bestArrange[i] , costs[i][bestArrange[i]] );
	}
	FILE*f;
	if(d==3)
	f = fopen ( "1out.txt","w" );
	else if(d==10)
	f = fopen ( "10out.txt","w" );
	else if(d==20)
	f = fopen ( "20out.txt" , "w" );
	if (f == NULL)
	{
		printf ( "��ȡ�ļ�����" );
		return;
	}
	fprintf ( f , "��С����Ϊ��%d\n" , min_sum_cost );
	for (int i = 1; i <= n; i++)
	{
		fprintf ( f,"����%d���������%d,����Ϊ%d\n" , i , bestArrange[i] , costs[i][bestArrange[i]] );
	}
	fclose ( f );
}
int main ()
{
	min_sum_cost = 10000;
	while(1)
	{
		int d;
		cout<<"��ѡ�����ݹ�ģ"<<endl;
		cout<<"test�汾����3�����ݹ�ģ10����10�����ݹ�ģ20����20"<<endl;
		cin>>d; 
		clock_t start,finish;
	start=clock();
	readFile (d);
	getMinSumCost ( 1 , 0 );
	writeFile (d);
	finish=clock();
	printf("�����10���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",(double)(finish-start));
	 } 
	
}

