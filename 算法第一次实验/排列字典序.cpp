#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int f(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return n*f(n-1);
	}
}
int getvalue(int *a,int n)
{
	int sum=0;
	int count=0;
	for(int i=0;i<n-1;i++)
	{
		count=0;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				count++;
			}
		}
		sum=sum+count*f(n-i-1);
	}
	
	return sum;
	
}
void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}
void getnext(int *a,int n)
{
	int flag;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>a[i-1])
		{
			flag=i-1;
			break;
		}
	}
	for(int i=n-1;i>flag;i--)
	{
		if(a[i]>a[flag])
		{
			swap(a[i],a[flag]);
			break;		
		}
	}
	sort(a+flag+1,a+n);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<getvalue(a,n)<<endl;
	getnext(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
