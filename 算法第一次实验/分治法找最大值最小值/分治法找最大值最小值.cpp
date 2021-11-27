#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
int max(int num1,int num2)
{
	if(num1>num2)
	return num1;
	else
	return num2;
}
int min(int num1,int num2)
{
	if(num1<num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
void search(int *a,int l,int r,int& maxn,int& minn)
{
	if(l==r)
	{
		maxn=a[l];
		minn=a[l]; 
	}
	else
	{
		int mid=(l+r)/2;
		int max1,max2,min1,min2;
		search(a,l,mid,max1,min1);
		search(a,mid+1,r,max2,min2);
		maxn=max(max1,max2);
		minn=min(min1,min2);
	}
}
int main()
{
	while(1)
	{
		int maxc,minc;
	int c;
	cout<<"请选择数据规模"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	cin>>c;
	ifstream file;
	ofstream file1;
	if(c==100)
	{
		file.open("100.txt");
		file1.open("100out.txt");
	} 
	else if(c==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt");
	} 
	else if(c==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt");
	} 
	else if(c==100000)
	{
		file.open("100000.txt");
		file1.open("100000out.txt");
	} 
	int a[c];
	for(int i=0;i<c;i++)
	{
		file>>a[i];
	}
	clock_t start,finish;
	start = clock();
	search(a,0,c-1,maxc,minc);
	finish = clock();
	cout<<maxc<<" "<<minc<<endl;
	file1<<maxc<<" "<<minc<<endl;
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",c,(double)(finish-start));
	}
}
