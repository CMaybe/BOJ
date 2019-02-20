#include<stdio.h>
int arr[501][501];
int main()
{
	int n,max=-1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i - 1][j - 1] > arr[i - 1][j] ? arr[i - 1][j - 1] : arr[i - 1][j];
			if (max < arr[i][j]) max = arr[i][j];
		}

	}
	printf("%d", max);

}
