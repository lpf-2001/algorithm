#include<bits/stdc++.h>
using namespace std;
ifstream file;
ofstream file1;
int Bsearch(int len,vector<int> b,int n)
{
	int left = 1;
	int right = len;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (b[mid] > n)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	return right;
}
int getresult(int a[],int n)
{
	int tempindex;
	int count=0; 
	vector<int> b(n+1,0);
	for(int i=0;i<n;i++)
	{
		if(a[i]<=b[i+1])
		{
			tempindex=Bsearch(i+1,b,a[i]);
			b[tempindex]=a[i];
		}
		else
		{
			b[i+2]=a[i];
			count++;
		}
	}
	cout<<count<<endl;
	file1<<count;
}
int main()
{
		clock_t start,finish;
	cout<<"请选择数据规模"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	int d;
	cin>>d; 
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
	
	int a[d];
	for(int i=0;i<d;i++)
	{
		file>>a[i];
	}
	start=clock();
	getresult(a,d);
	finish=clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
}
