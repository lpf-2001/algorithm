#include<fstream>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream file("test.txt");
	int d;
	cin>>d;
	file<<d<<endl;	
	int c;
	int a[d][d];
	for(int i=0;i<d;i++)
	{
		for(int k=i;k<d;k++)
			{
				if(k!=i)
				{
					c=rand()%100;
				a[i][k]=c;
				a[k][i]=a[i][k];
				}
				else
				{
					a[i][k]=0;
					a[k][i]=0;
				}
				
		}
	}
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			if(j<d-1)
			file<<a[i][j]<<" ";
			else
			file<<a[i][j];
		}
		file<<'\n';
	}
	
}
