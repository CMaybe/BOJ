#include<cstdio>


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = j, y = i;
			while (y) {
				if (x % 3 == 1 && y % 3 == 1) {
					break;
				}
				x /= 3;
				y /= 3;
			}
			(y != 0) ? printf(" ") : printf("*");
		}
		printf("\n");
	}
	return 0;
}
