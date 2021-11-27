#include<stdio.h>
#include<time.h>
int main()
{ 
    while(1)
    {
    	
    	int n;
    	clock_t start,finish;
		start = clock();	
    	scanf("%d", &n);
    	if(!n) break;
    	printf("\n");
    	for(int i = 1; i <= n; ++i)
   	 	{
    	    for(int j = 1; j <= n; ++j)
   	        printf("%d ", ((i+j+(n-3)/2)%n)*n+(i-j+(3*n-1)/2)%n+1);
        	printf("\n");
    	}
		finish = clock();
		printf("解决此%d数据规模所需的时间为：%.2f ms\n",n,(double)(finish-start));
	}
    return 0;
}

