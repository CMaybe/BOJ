#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int arr[4][100002];
int max;
int main()
{
	int n, t;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		max = -1;
		for (int j = 1; j <= 2; j++) {
			for (int k = 1; k <= n; k++) {
				scanf("%d", &arr[j][k]);
			}
		}
		for (int k = 2; k <= n; k++) {
			arr[0][k] = arr[1][k-1] > arr[2][k-1] ? arr[1][k-1] : arr[2][k-1];
			if (max < arr[0][k])max = arr[0][k];
			arr[1][k] += arr[0][k-1] > arr[2][k-1] ? arr[0][k-1] : arr[2][k-1];
			if (max < arr[1][k])max = arr[1][k];
			arr[2][k] += arr[0][k-1] > arr[1][k-1] ? arr[0][k-1] : arr[1][k-1];
			if (max < arr[2][k])max = arr[2][k];

		}
		printf("%d\n", max);

	}
}
