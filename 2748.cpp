#include<stdio.h>

int main()
{
	long long int a, b, c, n; //a 1 b 2
	scanf("%lld", &n);
	a = 0;
	b = 1;
	c = a + b;
	while (n-2 > 0)
	{
		a = b;
		b = c;
		c = a + b;
		n--;///n-=1;
	}
	printf("%lld", c);

}
