#include <stdio.h>
#include <stdlib.h>
 
#define INF 10000
 
int coin[ 5 ] = {0,25,10,5,1};
int numb[ 5 ];
int f[ 501 ][ 5 ];
 
int main()
{
    double A,C[ 5 ];
    while ( scanf("%lf",&A) != EOF ) {
        for ( int i = 1 ; i <= 4 ; ++ i )
            scanf("%d",&numb[ i ]);
        
        for ( int i = 0 ; i <= 500 ; ++ i )                           //行号代表价值 ，列代表金币使用情况 ，0列代表总金币数 
        for ( int j = 0 ; j <= 4 ; ++ j )
            f[ i ][ j ] = INF;
        for ( int i = 0 ; i <= 4 ; ++ i )
            f[ 0 ][ i ] = 0;
        
        int V = int(100*A+0.5);
        for ( int i = 1 ; i <= 4 ; ++ i ) {                            //求出该价值可能组合 
            for ( int j = numb[ i ] ; j >= 1 ; -- j )
            for ( int k = V ; k >= coin[ i ] ; -- k )
                if ( f[ k ][ 0 ] > f[ k-coin[ i ] ][ 0 ] + 1 ) {
                    for ( int l = 0 ; l <= 4 ; ++ l )
                        f[ k ][ l ] = f[ k-coin[ i ] ][ l ];         //更新金币使用情况 
                    f[ k ][ 0 ] += 1;                               //总金币数加1 
                    f[ k ][ i ] += 1;                                //因为需要多一个coin[i]面值的金币 
                }
        }
        if ( f[ V ][ 0 ] == INF )                          //如果这一行的第一个元素也就是你的价值对应的金币可能组合如果是INF说明没有组合 
            printf("NO EXACT CHANGE\n");
        else {
            for ( int i = 1 ; i <= 4 ; ++ i ) {
                printf("%d",f[ V ][ i ]);
                if ( i == 4 ) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}

