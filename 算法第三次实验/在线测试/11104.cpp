#include <iostream>
#include <sstream>
#include<cstdio>
#include<cstring>
using namespace std;
int t[10][101];
void CountLess(int l, int m)
{
	int maxx,minn,get;
	for(int i=2;i<l;i++)
	{ 
		for(int j=1;j<=m;j++)
		{
			maxx=min(j,9);
			get=0;
			for(int k=0;k<=maxx;k++)
				get+=t[i-1][j-k];
			t[i][j]=get;
		} 
	}
}
int Tot(long long n,int m)
{
	int i,j,k,l,minn,maxx,get1,get2;
	stringstream ss;
	string str;
	ss<<n;
	ss>>str;
	l=str.length();
	for(i=0;i<=l;i++)
		t[i][0]=0; 
	for(i=0;i<=m;i++)
	{
		t[0][i]=0;
		t[1][i]=min(i,9);
	}
	CountLess(l,m);
	get1=0;
	for(i=1;i<l;i++)
		get1+=t[i][m];
	for(i=0;i<=m;i++)
		t[1][i]=min(i+1,10);
	for(i=1;i<=l;i++)
		t[i][0]=1;
	CountLess(l,m);
	int MaxSum=m,num,off=0;
	get2=0;
	for(i=1;i<=l;i++)
	{
		num=str[i-1]-'0';
		minn=(i==1?1:0);
		maxx=min(MaxSum,num-1);
		if(l-i==0) off=1;
		for(j=minn;j<=maxx;j++)
		{
			get2+=(t[l-i][MaxSum-j]);
			get2+=off;
		}
		MaxSum-=num;
		if(MaxSum<0) break;
	}
	if(MaxSum>=0&&n) get2++;
	return get1+get2;
}
int main()
{
	int n,m;
	while(cin>>n)
	{
		cin>>m;
		cout<<Tot(n,m)+1<<'\n';
	}
	return 0;
}

