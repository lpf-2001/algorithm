#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include <bits/stdc++.h>
#define MAXN 30            
using namespace std;
int n , min_sum_cost;//记录工人工作总数，总费用
int costs[MAXN][MAXN];//记录将工作i分配给第j个人所需的费用，记为costs[i][j]
int visited[MAXN];//visited[i]用于记录工人i是否已经被分配工作，0表示未分配，1表示已分配
int arrange[MAXN];//记录当前安排情况
int bestArrange[MAXN];//记录最优安排情况

//从文件中读取数据并输出到控制台
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
		printf ( "读取文件错误" );
		return;
	}
	fscanf (f,"%d" , &n );
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fscanf(f, "%d" , &costs[i][j] );
	}
	printf ( "%d项工作分别分配给%d个工人的工作费用详细为:\n",n,n );
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

//回溯法求最小总费用
void getMinSumCost ( int i , int sum )// i表示当前正在分配的工作，sum表示花费
{
	if (sum > min_sum_cost) //如果当前花费已经大于已知的最小花费，则剪枝 
		return;
	if (i == n + 1 && sum < min_sum_cost)//分配完所有的工作返回结果
	{
		min_sum_cost = sum;
		memcpy ( bestArrange , arrange , sizeof ( arrange ) );
		return;
	}

	for (int j = 1; j <= n; j++)//为第1到第n个人分配工作
	{
		if (!visited[j]) //如果工人j未被分配工作
		{
			visited[j] = 1;//将其改为已分配状态
			arrange[i] = j;//表示工作i分配给工人j
			getMinSumCost ( i + 1 , sum+ costs[i][j] );//递归解决第i+1个工作
			visited[j] = 0;//回溯
		}
	}
}

//将结果存入文件output.txt并输出到控制台
void writeFile (int d )
{
	printf ( "最小总花费为：%d\n" , min_sum_cost );
	for (int i = 1; i <= n; i++)
	{
		printf ( "工作%d分配给工人%d,花费为%d\n" , i , bestArrange[i] , costs[i][bestArrange[i]] );
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
		printf ( "读取文件错误" );
		return;
	}
	fprintf ( f , "最小花费为：%d\n" , min_sum_cost );
	for (int i = 1; i <= n; i++)
	{
		fprintf ( f,"工作%d分配给工人%d,花费为%d\n" , i , bestArrange[i] , costs[i][bestArrange[i]] );
	}
	fclose ( f );
}
int main ()
{
	min_sum_cost = 10000;
	while(1)
	{
		int d;
		cout<<"请选择数据规模"<<endl;
		cout<<"test版本输入3，数据规模10输入10，数据规模20输入20"<<endl;
		cin>>d; 
		clock_t start,finish;
	start=clock();
	readFile (d);
	getMinSumCost ( 1 , 0 );
	writeFile (d);
	finish=clock();
	printf("解决此10数据规模所需的时间为：%.2f ms\n",(double)(finish-start));
	 } 
	
}

