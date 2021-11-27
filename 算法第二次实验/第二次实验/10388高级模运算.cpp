#include<iostream>
using namespace std;
int n;
long long binPow(long long x,long long y,int n)
{//ab=a2^b0+2^b1+?-+2^bk=a2^b0?¨¢a2^b1?¨¢a2^bk
    long long ans=1;
    while(y!=0)
    {
        if(y%2==1)
            ans=ans*x%n;
        y>>=1;
        x=x*x%n;
    }
    return ans;
}
int fun2(long long int a,long long int b,int n)
{
    int t;
    if (b == 1)//µİ¹é½áÊø
        return a%n;

   if (b % 2 == 0)
   {
       t = fun2 (a, b/2,n);
       return t * t%n;
   }
   else {
    t = fun2 (a, b/2,n);
    return t * t * a%n;
   }
}

int all(int num,int a[],int b[],int l,int r)
{
	int mid;
	mid=(l+r)/2;
	if(l>r) return 0;
	if(l==r) 
	{
		return fun2(a[l],b[l],n);
	}
	if(l<r) return (all(num,a,b,l,mid)+all(num,a,b,mid+1,r))%n;
}

int main()
{

	scanf("%d",&n);
	int num;
	scanf("%d",&num);
	int a[num];
	int b[num];
	int sum=0;
	for(int i=0;i<num;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	sum=all(num,a,b,0,num-1)%n;
	printf("%d",sum); 
 } 
