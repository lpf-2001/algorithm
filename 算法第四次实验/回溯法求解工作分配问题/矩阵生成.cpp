#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream file("20.txt",ios::app);
	file<<20<<endl;
	for(int i=0;i<20;i++)
	{
		for(int k=0;k<20;k++)
			{
				file<<rand()%100;
				if(k<99)file<<" ";
			}
			file<<endl;
		}
	
}
