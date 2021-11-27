
#include <stdio.h>
#include <math.h>
 
int fib_4[15010] = {0, 1}, fib[40] = {0, 1};
const double x = log10(1.0 / sqrt(5.0));
const double y = log10((1.0 + sqrt(5.0)) / 2.0);                        //用来计算前四位，通过斐波那契数列递推公式以及当n很大的时候通过化简得到的一个公式来算
 
int main() {
	int n, i, b;
	double a;
	for (i = 2; i < 40; ++i) fib[i] = fib[i-1] + fib[i-2];            //如果n小于40，最终结果不超过8位 
	for (i = 2; i <= 15000; ++i) {                                 //后四位循环节是15000 
		fib_4[i] = fib_4[i-1] + fib_4[i-2];                      //计算后四位
		if (fib_4[i] >= 10000) fib_4[i] -= 10000;
	}
	while (scanf("%d", &n) == 1) {
		if (n < 40) printf("%d\n", fib[n]);     
		else {
			a = x + n * y;
			a -= (int)a;    
			a = pow(10, a);                                             
			printf("%d...%0.4d\n", (int)(a * 1000), fib_4[n%15000]);    //前四位通过斐波那契数列的递推公式以及当n很大的时候通过化简得到的一个公式来算 
		}
	}
	return 0;
}

