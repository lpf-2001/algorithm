#include<iostream>
#include<stdlib.h>
#include<string> 
#include<time.h> 
#include<fstream>
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream file;
	int a[4]={100,1000,10000,100000};

	int j;
			cin>>j;
			switch(j)
			{
				case 0:{
				file.open("100.txt");
				break;
			}
			case 1:{
				file.open("1000.txt");
				break;
			}
			case 2:{
				file.open("10000.txt");
				break;
			}
			case 3:{
				file.open("100000.txt");
				break;
			}
			}
			
		for(int i=0;i<a[j];i++)
		{
			file<<rand()%10+1<<endl;
		}	


		
} 
