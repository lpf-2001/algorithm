#include<cstdlib> 
#include <fstream>
#include <iostream>
#include <time.h>
//***本程序用于产生随机数据
using namespace std;//RAND_MAX=32767
int a[1000]={0};
int b[1000]={0};
int c[1000]={0};
int n,m;
int Size[3]={10,100,1000};//文件大小
void print(ofstream &outfile,int n,int m)//输出到文件 
{
	outfile<<n<<" "<<m<<endl;
	for(int i=0;i<n;i++)
	{
		outfile<<a[i]<<' '<<b[i]<<' '<<c[i]<<endl;
	}
}
int main()
{
    int n=0;
    //ifstream
    ofstream out_10("10.txt"),out_100("100.txt"),out_1000("1000.txt");//输入代查找数据;
    srand(time(NULL));//时间种子
    //生成测试文件
    for(int i=0;i<Size[0];i++) 
	{	
		m=rand()%20+1; //边数 
		a[i]=rand()%10+1;//得到[0,10)内的数
		b[i]=rand()%10+1;
		c[i]=rand()%100+1; 
	}
    print(out_10,Size[0],m);
    for(int i=0;i<Size[1];i++) 
	{
		m=rand()%100+100; //边数 
		a[i]=rand()%10+1;//得到[0,10)内的数
		b[i]=rand()%10+1;
		c[i]=rand()%100+1; 
	}
    print(out_100,Size[1],m);
    for(int i=0;i<Size[2];i++) 
	{
		m=rand()%500+500; //边数 
		a[i]=rand()%10+1;//得到[0,10)内的数
		b[i]=rand()%10+1;
		c[i]=rand()%100+1; 
	}
    print(out_1000,Size[2],m);
}
 
