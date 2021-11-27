
#include <stdio.h>
#include <math.h>
 
int fib_4[15010] = {0, 1}, fib[40] = {0, 1};
const double x = log10(1.0 / sqrt(5.0));
const double y = log10((1.0 + sqrt(5.0)) / 2.0);                        //��������ǰ��λ��ͨ��쳲��������е��ƹ�ʽ�Լ���n�ܴ��ʱ��ͨ������õ���һ����ʽ����
 
int main() {
	int n, i, b;
	double a;
	for (i = 2; i < 40; ++i) fib[i] = fib[i-1] + fib[i-2];            //���nС��40�����ս��������8λ 
	for (i = 2; i <= 15000; ++i) {                                 //����λѭ������15000 
		fib_4[i] = fib_4[i-1] + fib_4[i-2];                      //�������λ
		if (fib_4[i] >= 10000) fib_4[i] -= 10000;
	}
	while (scanf("%d", &n) == 1) {
		if (n < 40) printf("%d\n", fib[n]);     
		else {
			a = x + n * y;
			a -= (int)a;    
			a = pow(10, a);                                             
			printf("%d...%0.4d\n", (int)(a * 1000), fib_4[n%15000]);    //ǰ��λͨ��쳲��������еĵ��ƹ�ʽ�Լ���n�ܴ��ʱ��ͨ������õ���һ����ʽ���� 
		}
	}
	return 0;
}

