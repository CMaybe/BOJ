#include<cstdio>

int main()
{
	int a,b;
	scanf("%d %d", &a,&b);
	int t = a*60 + b;
	t -= 45;
	if (t < 0) t += 24 * 60;
	printf("%d %d", t / 60, t % 60);
	return 0;
}
