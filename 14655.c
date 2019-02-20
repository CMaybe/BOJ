#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,a ,sum = 0;
  scanf("%d", &n)
	for (n; n > 0; n--) {
		scanf("%d", &a);
		sum += abs(a);
	}
	printf("%d", sum * 2);
}
