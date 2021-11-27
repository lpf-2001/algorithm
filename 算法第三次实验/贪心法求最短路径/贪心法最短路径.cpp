#include <bits/stdc++.h> 
using namespace std;
#define INF 9999
ifstream file;
ofstream file1;
int findmins(vector<bool> &f,vector<int> s)                       //寻找当前最短路径的点 
{
	int min=INF,index=0;
	for(int i=1;i<s.size();i++)
	{
		if(f[i]==false&&s[i]<min)                                //这个点没有被处理过并且当前路径最短就可以被返回进行处理 
		{
			min=s[i];
			index=i;
		}
	}
	return index;
}
void dj(vector<vector<int> > a,int n)
{
	vector<int>s(n,INF);
	vector<bool>f(n,false);                                        //f数组记录点是否被处理 
	f[0]=true;
	for(int i=0;i<a[0].size();i++)
	{
		s[i]=a[0][i];
	}
	int j=findmins(f,s);                                           //起点从0点开始 
	while(j!=0)
	{
		for(int i=0;i<a[j].size();i++)
		{
			if(a[j][i]+s[j]<s[i])
			{
				s[i]=a[j][i]+s[j];
			}
		}
		f[j]=true;
		j=findmins(f,s);                                           //找到要处理的当前路径最短的点 
	}
	file1<<"从起点到各点距离"<<endl;
	cout<<"从起点到各点距离"<<endl;
	for(int i=0;i<n;i++)
	{
		file1<<s[i]<<" ";
		cout<<s[i]<<" ";	
	}
}
int main()
{
	clock_t start,finish;
	cout<<"请选择数据规模"<<endl;
	cout<<"10"<<" "<<"100"<<" "<<"1000"<<endl;
	int d;
	cin>>d; 
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
	int n,lnum;
	file>>n;
	vector<vector<int> > a(n,vector<int>(n,INF));                        
	file>>lnum;                                    //记录边数
	int p1,p2,v;
	for(int i=0;i<lnum;i++)
	{
		file>>p1>>p2>>v;
		a[p1-1][p2-1]=v;
	}
	start=clock();
	dj(a,n);
	finish=clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
}
