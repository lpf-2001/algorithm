#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	srand(time(NULL));
	ofstream file1("100.txt");
	ofstream file2("1000.txt");
	ofstream file3("10000.txt");
	ofstream file4("100000.txt");
	for(int i=0;i<100;i++)
	{
		file1<<rand()<<endl;
	}
	for(int i=0;i<1000;i++)
	{
		file2<<rand()<<endl;
	}
	for(int i=0;i<10000;i++)
	{
		file3<<rand()<<endl;
	}
	for(int i=0;i<100000;i++)
	{
		file4<<rand()<<endl;
	}

}
