#include <bits/stdc++.h> 
using namespace std;
#define INF 9999
ifstream file;
ofstream file1;
int findmins(vector<bool> &f,vector<int> s)                       //Ѱ�ҵ�ǰ���·���ĵ� 
{
	int min=INF,index=0;
	for(int i=1;i<s.size();i++)
	{
		if(f[i]==false&&s[i]<min)                                //�����û�б���������ҵ�ǰ·����̾Ϳ��Ա����ؽ��д��� 
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
	vector<bool>f(n,false);                                        //f�����¼���Ƿ񱻴��� 
	f[0]=true;
	for(int i=0;i<a[0].size();i++)
	{
		s[i]=a[0][i];
	}
	int j=findmins(f,s);                                           //����0�㿪ʼ 
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
		j=findmins(f,s);                                           //�ҵ�Ҫ����ĵ�ǰ·����̵ĵ� 
	}
	file1<<"����㵽�������"<<endl;
	cout<<"����㵽�������"<<endl;
	for(int i=0;i<n;i++)
	{
		file1<<s[i]<<" ";
		cout<<s[i]<<" ";	
	}
}
int main()
{
	clock_t start,finish;
	cout<<"��ѡ�����ݹ�ģ"<<endl;
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
	file>>lnum;                                    //��¼����
	int p1,p2,v;
	for(int i=0;i<lnum;i++)
	{
		file>>p1>>p2>>v;
		a[p1-1][p2-1]=v;
	}
	start=clock();
	dj(a,n);
	finish=clock();
	printf("�����%d���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",d,(double)(finish-start));
}
