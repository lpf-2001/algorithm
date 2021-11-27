#include<iostream>
#include<fstream> 
#include<time.h> 
using namespace std;
const int INF=99999;          //无穷大 
int n=8,m=6;              //n是行，m是列 
const int N=101;
int a[N][N];int b[N][N];int c[N][N];               //c为原矩阵，b为目标矩阵，a为临时存储 
int need=0;                                  //变换次数 
void changel(int i,int j)                  //列变化 交换第i列和第j列
{
	int s;
	for(int k=0;k<n;k++)
	{
		s=a[k][i];
		a[k][i]=a[k][j];
		a[k][j]=s;
	}
	if(i!=j)need++;	
} 
void changeh(int h)
{
	for(int i=0;i<m;i++)
	{
		if(a[h][i]==1)
		{
			a[h][i]=0;
		}
		else
		{
			a[h][i]=1;
		}
	}
	need++;
}
bool same(int i,int j)        //判断原矩阵的i列和目标矩阵的j列是否相等 
{
	for(int k=0;k<n;k++)
	{
		if(a[k][i]!=b[k][j])
		return 0;
	}
	return 1;
}
int main()
{
	while(1)
	{ 
	clock_t start,finish;
	start = clock();
	int d;
	cout<<"请选择数据规模"<<endl;
	cout<<"数据规模为10,行列变换的矩阵"<<" "<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	cout<<"如果选择行列变换100数据规模矩阵请选2"<<endl;
	cin>>d;
	ifstream file;
	ofstream file1; 
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
	else if(d==2)
	{
		file.open("行列变换100.txt");
		file1.open("行列变换100out.txt");
		d=100;
	}
	else if(d==1000)
	{
		file.open("1000.txt");
		file1.open("1000out.txt");
	} 
	else if(d==10000)
	{
		file.open("10000.txt");
		file1.open("10000out.txt");
	} 
	else if(d==100000)
	{
		file.open("100000.txt");
		file1.open("100000out.txt");
	} 
	for(int os=0;os<d;os++)                     //要处理d个矩阵 
	{
		int ans=INF;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				file>>c[i][j];
			}	
		}                                       //原矩阵c 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				file>>b[i][j];
			}	
		}                                       //目标矩阵b       
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<b[i][j]<<" ";        //查看文件里的目标矩阵是否传送正确 
		}
		cout<<endl;
	 } */ 
	for(int i=0;i<m;i++)                     //对于一个矩阵开始处理 
	{
		need=0;
		for(int o=0;o<n;o++)
		{
			for(int k=0;k<m;k++)
			{
				a[o][k]=c[o][k];
			}
		}
		if(i!=0)         //如果处理的不是原矩阵第一列，就得换 
		changel(i,0);
		for(int j=0;j<n;j++)
		{
			if(a[j][0]!=b[j][0])
			{
				changeh(j);
			}	
		}	
		bool find;
		int j; 
		for(j=0;j<m;j++)          //寻找接下来是否每一列都相等或者通过变换相等 
		{
			find=0;
			if(same(j,j)){
				find=1;
				continue;
			}
			for(int k=j+1;k<m;k++)
			{
				if(same(k,k)){
					find=1;
					continue;	
				}
				if(same(k,j)){
					find=1;
					changel(k,j);	
					break; 
				}
			}
			if(find==0||(find==1&&!same(j,j)))
			{
				break;
			}
			if(find==0)break;
		}
		if(find==1&&!same(j,j))            //避免除了第j列其他列都相同的情况 
		{
			need=INF;
		}
		if(find==1&&need<ans)
		{
			ans=need;
		}
	}
	
	if(ans!=INF)
	{
		file1<<ans<<endl;
		cout<<ans<<endl;	
	}
	
	else
	{
		file1<<-1<<endl;
		cout<<-1<<endl;
	}
		
	}
	finish = clock();
	printf("解决此%d个矩阵数据规模所需的时间为：%.2f ms\n",d,(double)(finish-start));
	}
	
	
} 
