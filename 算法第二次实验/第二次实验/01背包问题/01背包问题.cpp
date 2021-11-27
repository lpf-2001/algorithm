#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream> 
using namespace std;

int main()
{
	clock_t start,finish;
	cout<<"请选择数据规模"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	int d;
	cin>>d;
	ifstream file;
	ofstream file1; 
	if(d==100)
	{
		file.open("100.txt");
		file1.open("100out.txt");
	} 
	else if(d==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt");
	} 
	else if(d==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt");
	} 
	else if(d==100000)
	{
		file.open("100000.txt");
		file1.open("100000out.txt");
	} 

	int bsg;
	bsg=rand()%1000;
	int n;
	n=d;
	int X[n];
	for(int i=0;i<n;i++)
	{
		X[i]=0;
	}
	int w[n];
	int v[n];
	for(int i=0;i<n;i++)
	{
		file>>v[i]>>w[i];
	}
	int y[n+1][bsg+1];
	start=clock();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<bsg;j++)
		{
			
			
				y[i][j]=0;
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=bsg;j++)
		{
			if(w[i]>j)
			{
				y[i][j]=y[i-1][j];
			}
			else
			{
				y[i][j]=max(y[i - 1][j], y[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	file1<<"背包容量为"<<bsg<<endl;
	file1<<d<<"个背包"<<endl;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=bsg;j++)
		{
			cout<<y[i][j]<<" ";
			file1<<y[i][j]<<" ";
		}
		file1<<endl;
		cout<<endl;
	}
	finish=clock();
	cout<<endl;
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
} 
