#include<stdio.h>
int main()
{
	int a,c,b=0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		scanf("%d", &c);
		if (c != i)b++;
	}
	printf("%d", b);
}
