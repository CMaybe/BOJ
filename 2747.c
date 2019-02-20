#include<stdio.h>

int mem[18] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };

int fibo(int num)
{
	if (num < 18)
		return mem[num];
	else return fibo(num - 1) + fibo(num - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", fibo(n));
}
