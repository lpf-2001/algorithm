#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream file("ÐÐÁÐ±ä»»100.txt");
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<8;j++)
		{
			for(int k=0;k<6;k++)
			{
				file<<rand()%2;
				if(k<5)file<<" ";
			}
			file<<endl;
		}
	}
}
