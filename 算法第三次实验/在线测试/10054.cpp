#include<iostream>
#include<cstdio>
#include<algorithm>
#define R register
using namespace std;
const int N=100010;
int a[N],d1[N],d2[N],n;
inline bool read(int &x) {                            //用内联函数提升速度
    char c=getchar();
    if(c==EOF)return false;
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return true;
}
int main() {
    while(read(a[++n]));n--;                                        //保证了按照题目所给输入格式
    R int len1=1,len2=1;
    d1[1]=d2[1]=a[1];
    for(R int i=2; i<=n; i++) {
        if(d1[len1]>=a[i])d1[++len1]=a[i];
        else *upper_bound(d1+1,d1+1+len1,a[i],greater<int>())=a[i];            //找最长单调不减序列
        if(d2[len2]<a[i])d2[++len2]=a[i];
        else *lower_bound(d2+1,d2+1+len2,a[i])=a[i];                   //找最长单调递减序列
    }
    printf("%d\n%d",len1,len2);
    return 0;
}
