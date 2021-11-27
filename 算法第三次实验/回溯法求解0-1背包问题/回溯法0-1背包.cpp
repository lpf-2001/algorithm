#include<bits/stdc++.h>
using namespace std;
int n;
int bestv=0;
int rv=0;
vector<int>best(1000,0);
void backtrace(int i,vector<int> w,vector<int> v,int c,vector<int> x,int value)
{
	if(i>=n)
	{
		if(value>bestv)
		{
			bestv=value;
			for(int i=0;i<n;i++)
			{
				best[i]=x[i];
			}
		}
		return;
	}
	if(w[i]<=c)
	{
		c=c-w[i];
		x[i]=1;
		value=value+v[i];
		rv-=v[i];
		backtrace(i+1,w,v,c,x,value);
	}
	rv=rv+v[i];
	if(rv-v[i]+value>bestv)
	{
		c=c+w[i];
		x[i]=0;
		value=value-v[i];
		backtrace(i+1,w,v,c,x,value);
	}
}
int main()
{
	clock_t start,finish;
	cout<<"请选择数据规模"<<endl;
	cout<<"10"<<" "<<"100"<<" "<<"1000"<<endl;
	int d;
	cin>>d;
	ifstream file;
	ofstream file1; 
	if(d==10)
	{
		file.open("10.txt");
		file1.open("10out.txt");
	} 
	else if(d==100)
	{
		file.open("100.txt");
		file1.open("100out.txt");
	} 
	else if(d==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt");
	} 
	
	
	
	int c;                           //背包容量 
	n=d;
	c=rand()%100;
	vector<int>w(n);
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		file>>w[i]>>v[i];	
		rv=rv+v[i];
	}	
	vector<int> x(n,0);              //构造解向量
	int value=0; 
	start=clock();
	backtrace(0,w,v,c,x,value);
	finish=clock();
	file1<<"背包个数为："<<n<<endl;
	file1<<"背包容量为："<<c<<endl; 
	file1<<"最大价值"<<bestv<<endl;
	file1<<"解向量为："<<endl;
	for(int i=0;i<d;i++)
	{
		file1<<best[i]<<" ";
	}
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
} 
