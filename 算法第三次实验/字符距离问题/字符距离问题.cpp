#include<bits/stdc++.h>
using namespace std;
#define INF 999
ifstream file;
ofstream file1;
int dist(char a,char b)
{
	return abs(a-b);
}
void val(string m,string n,int k)
{
	int ml,nl;
	ml=m.size();
	nl=n.size();
	int s[ml+1][nl+1];
	s[0][0]=0;
	for(int i=0;i<=ml;i++)
	{
		for(int j=0;j<=nl;j++)
		{
			if(i+j)                             //m��n�ַ�������һ�����Ȳ�Ϊ0 
			{
				s[i][j]=INF;
				int temp=s[i-1][j]+k;
				if(i&&temp<s[i][j])
				{
					s[i][j]=temp;
				}
				temp=s[i][j-1]+k;
				if(j&&temp<s[i][j])
				{
					s[i][j]=temp;
				}
				temp=s[i-1][j-1]+dist(m[i-1],n[j-1]);
				if(i&&j&&temp<s[i][j])
				{
					s[i][j]=temp;
				}
			}
		}
	}
	file1<<s[ml][nl];
}
int main()
{
	clock_t start,finish;
	cout<<"��ѡ�����ݹ�ģ"<<endl;
	cout<<"100"<<" "<<"1000"<<" "<<"100000"<<endl;
	int d;
	cin>>d; 
	if(d==100)
	{
		file.open("about100.txt");
		file1.open("about100out.txt");
	} 
	else if(d==1000)
	{
		file.open("about7000.txt");
		file1.open("about7000out.txt");
	} 
	else if(d==100000)
	{
		file.open("about200000.txt");
		file1.open("about200000out.txt");
	} 
	
	
	
	string a,b;
	int k;
	file>>a;
	file>>b;
	k=rand()%10;
	file1<<"k="<<k<<endl;
	start=clock();
	val(a,b,k);
	finish=clock();
	printf("�����%d���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",d,(double)(finish-start));
	
}
