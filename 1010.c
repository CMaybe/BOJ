#include <stdio.h>

int arr[31][31];
int main()
{
	int a, b, n;
	for (int i = 1; i <= 30; i++) {
		arr[i][1] = i;
		arr[i][0] = 1;
	}
	scanf("%d", &n);
	for (int k = 0; k < n; k++)
	{
		scanf("%d %d", &a, &b);
		for (int i = 2; i <= b; i++) {
			for (int j = 2; j <= a; j++) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		printf("%d\n", arr[b][a]);
	}

}
