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
        
        for ( int i = 0 ; i <= 500 ; ++ i )                           //�кŴ����ֵ ���д�����ʹ����� ��0�д����ܽ���� 
        for ( int j = 0 ; j <= 4 ; ++ j )
            f[ i ][ j ] = INF;
        for ( int i = 0 ; i <= 4 ; ++ i )
            f[ 0 ][ i ] = 0;
        
        int V = int(100*A+0.5);
        for ( int i = 1 ; i <= 4 ; ++ i ) {                            //����ü�ֵ������� 
            for ( int j = numb[ i ] ; j >= 1 ; -- j )
            for ( int k = V ; k >= coin[ i ] ; -- k )
                if ( f[ k ][ 0 ] > f[ k-coin[ i ] ][ 0 ] + 1 ) {
                    for ( int l = 0 ; l <= 4 ; ++ l )
                        f[ k ][ l ] = f[ k-coin[ i ] ][ l ];         //���½��ʹ����� 
                    f[ k ][ 0 ] += 1;                               //�ܽ������1 
                    f[ k ][ i ] += 1;                                //��Ϊ��Ҫ��һ��coin[i]��ֵ�Ľ�� 
                }
        }
        if ( f[ V ][ 0 ] == INF )                          //�����һ�еĵ�һ��Ԫ��Ҳ������ļ�ֵ��Ӧ�Ľ�ҿ�����������INF˵��û����� 
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

