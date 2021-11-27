#include <stdio.h>
#include<iostream>
#include <bits/stdc++.h>
#define max 9999
using namespace std;
int num ;
int g[max][max], x[max], bestx[max]; //best[]是用来存储最终的最短路径 
int cl=0;
int best = max;

//交换函数 
void swap(int &a, int &b)
{
	int tem = a;
	a= b;
	b =tem;
}


//下界公式为 min{cl + min1 + temmin}解释一下就是当前走过的路径+下一个要找的最短路径+剩下点的到其他点的最短路径（最后这个temmin是用贪心的思想求剩下没走过城市的最路径）
//当然，贪心毕竟不是从整体最优考虑，而是从局部最优考虑，所以，在后来的寻找中，如果找到比 cl + min1 + temmin求解出来的最短路径，则可以考虑往下找，否则剪枝。 
int  bound( int t)
{
	int min1=max ,min2=max, temmin=0;  //这里min与min2初始化一下 
	for(int i=t; i<=num; i++)
	{
		//这里求min1 
		if( g[x[t-1]][x[i]] != -1 && g[x[t-1]][x[i]]  < min1)
		{
			min1 =g[x[t-1]][x[i]]; //这里求要去的第t城市。选择当前到t路径最短的 
		}
		
		//这里求min2 
		for(int j =1; j<=num; j++) //贪心的思想，求剩下的路径的下界 
	     {
	     	if( g[x[i]][x[j]]!=-1 &&  g[x[i]][x[j]]!=0  && g[x[i]][x[j]] < min2)
	     	{
	     		min2 = g[x[i]][x[j]];
			 }
		 }
		 temmin += min2; //这里是剩下点的最短出出路径的和的累加 
	}
	return cl+ min1 + temmin;
}

//这里选择城市的方式类似于全排列问题，只不过这里加了 一个判断条件就是t与之前的城市t-1有路径，这里是有选择性的选择点（这里也叫剪枝）。 
void prim(int t)
{
	//如果到叶节点，则表示所有城市都走过了，这个时候就保存一下最短路径以及相应的城市顺序 ，当然是满足条件就是比之前的bext还要小的路径的长度，每次取最优 
	if(t>num)
	{
		if(g[x[num]][1]!=-1 &&  cl + g[x[num]][1] <best) //记得还有最后回到原点 ，这里必须是有到原点的一条路径 
		{
		  for(int i =1; i<=num; i++)
			{
			   bestx[i] =x[i];	 //将走过的顺序放入best数组中 
		    }
			best = cl + g[x[num]][1]; //保存加上回到原点的的路径 
		}
	}
	
	else{
		for(int j =t; j<=num; j++)
		{
			if( g[x[t-1]][x[j]] !=-1 && (bound(t)<best)) //满足条件的选择要选的城市的编号 
			{
				swap(x[j],x[t]);
				cl += g[x[t-1]][x[t]]; //注意，这里不是g[x[t-1]x[j]]，j改成t，因为上面的j与t的位置的数换了。 
				
				prim(t+1);
				
				//回溯，恢复走过的。 
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
//	printf("输入城市数： ");
//	scanf("%d",&num);
	f = fopen ( "test.txt","r" );
	fscanf(f, "%d" , &num);
	for(int i =1; i<=num; i++)
	{
		x[i] =i; //将城市编号放入一个数组中,初始化 
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
	 
	 prim(2); //这里是从第一个城市出发，开始要寻找第二个要走的城市 
	 f=fopen("testout.txt","w"); 
	printf("从1号城市出发，经过所有城市回到起点顺序为： "); 
	fprintf(f,"从1号城市出发，经过所有城市回到起点顺序为： "); 
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
	 printf("\n最短路径为:  %d", best); 
	  fprintf(f,"\n"); 
	 fprintf(f,"\n最短路径为:  %d", best); 
	finish=clock();
	printf("解决此10数据规模所需的时间为：%.2f ms\n",(double)(finish-start));
	 return 0;
 } 

