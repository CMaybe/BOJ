#include<stdio.h>

int arr[41][2];

int main()
{
	int a, n;
	arr[0][0] = 1;
	arr[1][1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= 40; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		printf("%d %d\n", arr[a][0], arr[a][1]);
	}

}