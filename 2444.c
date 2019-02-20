#include<stdio.h>
int main()
{
	int a, b, c, d;
	scanf("%d", &a);
	for (b = 1; b < a; b++)
	{
		for (d = a - 1; d >= b; d--)
		{
			printf(" ");
		}
		for (c = 0; c < 2 * b - 1; c++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (b = a; b >= 1; b--)
	{
		for (d = a-1; d >= b; d--)
		{
			printf(" ");
		}
		for(c=0;c<2*b-1;c++)
		{
			printf("*");
		}
		printf("\n");
	}
}
