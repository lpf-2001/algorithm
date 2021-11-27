#include<stdio.h>
#include<math.h>
#include<time.h>
unsigned sum(unsigned n)
{
    if(n<10)
        return n;
    else
        return (n%10)+sum(n/10);
}
 
void generate(unsigned n,int *g)
{
    while(n<10000)
    {
        unsigned t=n+sum(n);
        if(t>=10000||g[t]!=t)
            return;
        g[t]=n; 
        n=t;
    }
}
 
int main()
{
    unsigned n;
    int *g;                     //g数组存储生成元 
    clock_t start,finish;
		start = clock();	
    g=new int[10000];
    for(n=1; n<10000; ++n)
        g[n]=n;
    for(n=1; n<10000; ++n)
        generate(n,g);
    for(n=1; n<10000; ++n)
        if(g[n]==n)
            printf("%d\n",g[n]);
    
    finish = clock();
	printf("解决此%d数据规模所需的时间为：%.2f ms\n",n,(double)(finish-start));
	return 0;
}
