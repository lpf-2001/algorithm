#include <stdio.h>
#include<iostream>
#include <bits/stdc++.h>
#define max 9999
using namespace std;
int num ;
int g[max][max], x[max], bestx[max]; //best[]�������洢���յ����·�� 
int cl=0;
int best = max;

//�������� 
void swap(int &a, int &b)
{
	int tem = a;
	a= b;
	b =tem;
}


//�½繫ʽΪ min{cl + min1 + temmin}����һ�¾��ǵ�ǰ�߹���·��+��һ��Ҫ�ҵ����·��+ʣ�µ�ĵ�����������·����������temmin����̰�ĵ�˼����ʣ��û�߹����е���·����
//��Ȼ��̰�ıϾ����Ǵ��������ſ��ǣ����ǴӾֲ����ſ��ǣ����ԣ��ں�����Ѱ���У�����ҵ��� cl + min1 + temmin�����������·��������Կ��������ң������֦�� 
int  bound( int t)
{
	int min1=max ,min2=max, temmin=0;  //����min��min2��ʼ��һ�� 
	for(int i=t; i<=num; i++)
	{
		//������min1 
		if( g[x[t-1]][x[i]] != -1 && g[x[t-1]][x[i]]  < min1)
		{
			min1 =g[x[t-1]][x[i]]; //������Ҫȥ�ĵ�t���С�ѡ��ǰ��t·����̵� 
		}
		
		//������min2 
		for(int j =1; j<=num; j++) //̰�ĵ�˼�룬��ʣ�µ�·�����½� 
	     {
	     	if( g[x[i]][x[j]]!=-1 &&  g[x[i]][x[j]]!=0  && g[x[i]][x[j]] < min2)
	     	{
	     		min2 = g[x[i]][x[j]];
			 }
		 }
		 temmin += min2; //������ʣ�µ����̳���·���ĺ͵��ۼ� 
	}
	return cl+ min1 + temmin;
}

//����ѡ����еķ�ʽ������ȫ�������⣬ֻ����������� һ���ж���������t��֮ǰ�ĳ���t-1��·������������ѡ���Ե�ѡ��㣨����Ҳ�м�֦���� 
void prim(int t)
{
	//�����Ҷ�ڵ㣬���ʾ���г��ж��߹��ˣ����ʱ��ͱ���һ�����·���Լ���Ӧ�ĳ���˳�� ����Ȼ�������������Ǳ�֮ǰ��bext��ҪС��·���ĳ��ȣ�ÿ��ȡ���� 
	if(t>num)
	{
		if(g[x[num]][1]!=-1 &&  cl + g[x[num]][1] <best) //�ǵû������ص�ԭ�� ������������е�ԭ���һ��·�� 
		{
		  for(int i =1; i<=num; i++)
			{
			   bestx[i] =x[i];	 //���߹���˳�����best������ 
		    }
			best = cl + g[x[num]][1]; //������ϻص�ԭ��ĵ�·�� 
		}
	}
	
	else{
		for(int j =t; j<=num; j++)
		{
			if( g[x[t-1]][x[j]] !=-1 && (bound(t)<best)) //����������ѡ��Ҫѡ�ĳ��еı�� 
			{
				swap(x[j],x[t]);
				cl += g[x[t-1]][x[t]]; //ע�⣬���ﲻ��g[x[t-1]x[j]]��j�ĳ�t����Ϊ�����j��t��λ�õ������ˡ� 
				
				prim(t+1);
				
				//���ݣ��ָ��߹��ġ� 
				cl -= g[x[t-1]][x[t]];
				swap(x[j],x[t]);
			}
		}
	}
}


int main()
{
	clock_t start,finish;
	start=clock();
	FILE*f;
//	printf("����������� ");
//	scanf("%d",&num);
	f = fopen ( "test.txt","r" );
	fscanf(f, "%d" , &num);
	for(int i =1; i<=num; i++)
	{
		x[i] =i; //�����б�ŷ���һ��������,��ʼ�� 
		bestx[i] = 0;
	}
	
	for(int i =1; i<=num; i++)
	{
		for(int j =1; j<=num; j++)
		{
			//scanf("%d",&g[i][j]);
			fscanf(f, "%d" , &g[i][j] );
			cout<<g[i][j]<<endl;
		}
	 } 
	 
	 prim(2); //�����Ǵӵ�һ�����г�������ʼҪѰ�ҵڶ���Ҫ�ߵĳ��� 
	 f=fopen("testout.txt","w"); 
	printf("��1�ų��г������������г��лص����˳��Ϊ�� "); 
	fprintf(f,"��1�ų��г������������г��лص����˳��Ϊ�� "); 
	 for(int i =1; i<=num ;i++)
	 {
         printf("%d --> ", bestx[i]);
        fprintf(f,"%d --> ", bestx[i]);
	 }
	 
	 if(g[x[num]][1]!=-1);
	 {
	 	printf("%d",bestx[1]); 
	 	fprintf(f,"%d",bestx[1]);
	 }
	 
	 printf("\n"); 
	 printf("\n���·��Ϊ:  %d", best); 
	  fprintf(f,"\n"); 
	 fprintf(f,"\n���·��Ϊ:  %d", best); 
	finish=clock();
	printf("�����10���ݹ�ģ�����ʱ��Ϊ��%.2f ms\n",(double)(finish-start));
	 return 0;
 } 

