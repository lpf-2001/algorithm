#include<iostream>
#include<stdlib.h>
#include<string> 
#include<time.h> 
#include<fstream>
using namespace std;
int x;
int pailie(int m,int n)        //�������� 
{
	if(n==0)
	{
		return 0;
	}
	int km=1,kn=1;
	for(int i=1;i<=n;i++)
	{
		kn=kn*i;
	}
	for(int i=m-n+1;i<=m;i++)
	{
		km=km*i;
	}
	return km/kn;
}
int main()
{
	int n;
	ifstream input("test.txt");
	ofstream output("output.txt"); 
	input>>n;
	clock_t start,finish;
	start = clock();
	for(int rs=0;rs<n;rs++)
	{
		input>>x;
		char sop[x];
		int sum=1;
		string str(sop,x);
		int tp[x];
		for(int i=0;i<x;i++)
		{
			input>>tp[i];	
		} 
		for(int i=0;i<x;i++)
		{
			str[i]=tp[i]+'a';
		}
		
		int len;
		len=str.size();
		int a[len];
		for(int i=1;i<str.size();i++)
		{
			sum=sum+pailie(26,i);
		}
		for(int i=0;i<str.size();i++)
		{
			a[i]=str[i]-'a';
		}
		int temp=1;            //temp�洢ǰ���ж��ٸ���ĸ������ 
		for(int i=1;i<=str.size();i++)
		{
			                           
			for(int j=temp;j<=a[i-1];j++)
			{
				sum=sum+pailie(26-j,str.size()-i);
			}
			temp=2+a[i-1];                //ǰ����a[i-1]+1λ�����ã����ϵ�ǰһλ������ 
		}
		if(x!=1)
		{
			cout<<sum<<endl;
			output<<sum<<endl;
		}
		else
		{
			cout<<str[0]-'a'+1<<endl;
			output<<str[0]-'a'+1<<endl;
		}
	}
	finish = clock();
	printf("�����%d���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",n,(double)(finish-start));
}
