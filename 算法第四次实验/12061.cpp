#include<stdio.h>
#include<string.h>
using namespace std;
int h[30007],fp[30007],x1[30007*2],x2[30007*2]; //四个数组分别记录在同行出现的皇后棋数,同列出现的皇后棋数,同条对角线，出现的皇后棋数,同条斜对角线出现的皇后棋数
int main()
{
    int n,g;
    while(scanf("%d",&n)&&n!=0)
    {
        scanf("%d",&g);
        memset(h,0,sizeof(h));
        memset(fp,0,sizeof(fp));
        memset(x1,0,sizeof(x1));
        memset(x2,0,sizeof(x2));
        int k,x,y,s,t,ans=0;
        while(g--)
        {
 
            scanf("%d%d%d%d%d",&k,&x,&y,&s,&t);
            int temprow,tempcofp;
            for(int a=0; a<k; a++)
            {
                temprow=x+a*s;
                h[temprow]++;
                if(h[temprow]>=2)ans++;
                tempcofp=y+a*t;
                fp[tempcofp]++;
                if(fp[tempcofp]>=2)ans++;
                x1[temprow+tempcofp]++;
                if(x1[temprow+tempcofp]>=2)ans++;
                x2[temprow-tempcofp+n]++;
                if(x2[temprow-tempcofp+n]>=2)ans++;
            }
        }
 
        printf("%d\n",ans);
    }
    return 0;
}


