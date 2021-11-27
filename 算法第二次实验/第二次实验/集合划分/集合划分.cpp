#include<iostream>
#include<fstream>

#include<time.h> 
using namespace std;
int q(int n,int m)
{
	if(n==0)
	{
		return 0;
	}
	else if(m==1)
	{
		return 1;
	}
	else if(m>n)
	{
		return 0;
	}
	else if(m==n)
	{
		return 1;
	}
	else if(m<n)
	{
		return q(n-1,m-1)+m*q(n-1,m);
	}
}
int main()
{
	clock_t start,finish;
	start = clock();
	int d;
	int result;
	int num;
	cout<<"请选择数据规模"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
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
	start=clock();
	for(int i=0;i<d;i++)
	{
		file>>num;
		result=0;
		
		for(int j=1;j<=num;j++)
		{
			result=result+q(num,j);	
		}
		
		file1<<result<<endl;
		cout<<result<<endl;
		
	}  
	finish=clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
}
