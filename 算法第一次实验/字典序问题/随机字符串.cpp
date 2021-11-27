#include<iostream>
#include<stdlib.h>
#include<string> 
#include<time.h> 
#include<fstream>
using namespace std;
int main()
{
	int x;	
	ofstream output("test.txt");
	int num;
	srand(time(NULL));
	num=rand()%100+1;
	output<<num<<endl;
	for(int s=0;s<num;s++)
	{
	x=rand()%6+1;
	cout<<x<<endl;
	int tp[x];
	for(int i=0;i<x;i++)
	{
		tp[i]=0;
	}
	tp[0]=rand()%9;
	for(int i=1;i<x;i++)
	{
		tp[i]=rand()%5+1+tp[i-1];
		while(tp[i]>=26)
		{
			tp[i]=rand()%5+1+tp[i-1];
		}	
	}
	
	output<<x<<endl;
	for(int i=0;i<x;i++)
	{
		if(i<x-1)
		output<<tp[i]<<" ";
		else
		output<<tp[x-1];
	}
	output<<endl;
	}
	
}
