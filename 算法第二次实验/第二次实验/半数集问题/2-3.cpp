#include<iostream>
#include<fstream>
#include<time.h> 
using namespace std;
int banshu(int n)
{
	int sum=0;
	if(n==1)
	{
		return 1;
	}
	else
	{
		int x=n/2;
		for(int i=1;i<=x;i++)
		{
			sum=banshu(i)+sum;
		}
	}
	return sum+1;
}
int main()
{
	clock_t start,finish;
	start = clock();
	int d;
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
	int result;
	int num;
	start = clock();
	for(int i=0;i<d;i++)
	{
		file>>num;
		result=banshu(num);
		file1<<result<<endl;
		cout<<result<<endl;
	} 
	finish = clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
}
