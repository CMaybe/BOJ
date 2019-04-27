#include<cstdio>


int main()
{
	int a, b;
	while (true)
	{
		scanf("%d %d", &a, &b);
		if (!a * !b) break;
		printf("%d\n", a + b);
	}
	return 0;
}
