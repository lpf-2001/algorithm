#include<iostream>
#include<fstream> 
#include<time.h> 
using namespace std;
const int INF=99999;          //����� 
int n=8,m=6;              //n���У�m���� 
const int N=101;
int a[N][N];int b[N][N];int c[N][N];               //cΪԭ����bΪĿ�����aΪ��ʱ�洢 
int need=0;                                  //�任���� 
void changel(int i,int j)                  //�б仯 ������i�к͵�j��
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
bool same(int i,int j)        //�ж�ԭ�����i�к�Ŀ������j���Ƿ���� 
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
	cout<<"��ѡ�����ݹ�ģ"<<endl;
	cout<<"���ݹ�ģΪ10,���б任�ľ���"<<" "<<"100"<<" "<<"1000"<<" "<<"10000"<<" "<<"100000"<<endl;
	cout<<"���ѡ�����б任100���ݹ�ģ������ѡ2"<<endl;
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
		file.open("���б任100.txt");
		file1.open("���б任100out.txt");
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
	for(int os=0;os<d;os++)                     //Ҫ����d������ 
	{
		int ans=INF;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				file>>c[i][j];
			}	
		}                                       //ԭ����c 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				file>>b[i][j];
			}	
		}                                       //Ŀ�����b       
/*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<b[i][j]<<" ";        //�鿴�ļ����Ŀ������Ƿ�����ȷ 
		}
		cout<<endl;
	 } */ 
	for(int i=0;i<m;i++)                     //����һ������ʼ���� 
	{
		need=0;
		for(int o=0;o<n;o++)
		{
			for(int k=0;k<m;k++)
			{
				a[o][k]=c[o][k];
			}
		}
		if(i!=0)         //�������Ĳ���ԭ�����һ�У��͵û� 
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
		for(j=0;j<m;j++)          //Ѱ�ҽ������Ƿ�ÿһ�ж���Ȼ���ͨ���任��� 
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
		if(find==1&&!same(j,j))            //������˵�j�������ж���ͬ����� 
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
	printf("�����%d���������ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",d,(double)(finish-start));
	}
	
	
} 
