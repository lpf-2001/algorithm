#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
using namespace std;
void merge(int *a,int l,int r,int mid)
{
	int *temp;
	temp=new int[r-l+1];
	int i=l,j=mid+1;
	int k=0;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i];
			i++;
		}
		else
		{
			temp[k++]=a[j];
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=r)
	{
		temp[k++]=a[j++];
	}
	for(i=0,k=l;k<=r;i++,k++)
	{
		a[k]=temp[i];
	}
}
void fen(int *a,int l,int r)
{
	
	if(l<r)
	{
	int mid=(l+r)/2;
	fen(a,l,mid);
	fen(a,mid+1,r);
	merge(a,l,r,mid);
	}
	return;
}
int main()
{
	while(1)
	{
		int c;
	cout<<"请选择数据规模"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	cin>>c;
	int a[c];
	ifstream file;
	ofstream file1; 
	if(c==20)
	{
		file.open("20.txt");
		file1.open("20out.txt");
	} 
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
	for(int i=0;i<c;i++)
	{
		file>>a[i];
	}
	clock_t start,finish;
	start = clock();
	fen(a,0,c-1);
	finish = clock();
	for(int i=0;i<c;i++)
	{
		if(i<c-1)
		file1<<a[i]<<" ";
		else
		file1<<a[i];
		cout<<a[i]<<endl;
	}
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",c,(double)(finish-start));
	}
	
}
