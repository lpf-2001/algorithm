#include<algorithm>
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
struct thing{
	double w;
	double v;
	double p;          //存储单位重量价值
};
bool cmp(thing a,thing b)
{
	if(a.p>b.p)
	{
		return 1;
	}
	return 0;
}
double maxvalue(thing A[],int n,double weight,double X[])
{
	int i=0;
	double value;
	while(weight>A[i].w)
	{
		X[i]=1;
		weight-=A[i].w;
		value=value+A[i].v;
		i++;
	}
	if(weight>0)
	{
		value=value+(weight/A[i].w)*A[i].v;
		X[i]=weight/A[i].w;
	}
	return value;
}
int main()
{
	clock_t start,finish;
	srand(time(NULL));
	double weight;
	weight=rand()%1000;
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
	int n;
	n=d;
	start=clock();
	double X[n];
	for(int i=0;i<n;i++)
	{
		X[i]=0;
	}
	thing A[n];
	for(int i=0;i<n;i++)
	{
		file>>A[i].v>>A[i].w;
		A[i].p=A[i].v/A[i].w;
	}
	sort(A,A+n,cmp);
	file1<<"背包容量为"<<weight<<endl;
	file1<<"在"<<d<<"个背包中"<<endl; 
	file1<<"最大价值为";
	file1<<maxvalue(A,n,weight,X)<<endl;
	file1<<"其中解向量X{1...n}为:";
	for(int i=0;i<n;i++)
	{
		file1<<X[i]<<" ";
	}
	cout<<maxvalue(A,n,weight,X)<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<endl;
	finish=clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
}
