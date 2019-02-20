#include <stdio.h>
int main()
{
	int n,a,b,c,d,e=-1,k=0;
	scanf("%d", &n);
	a = n / 10;
	b = n % 10;
	c = a;
	d = b;
	do
	{
		k++;
		e = d;
		d = (c + d)%10;
		c = e;
	} while (a!=c|| b!=d);
	printf("%d", k);
    return 0;
}
