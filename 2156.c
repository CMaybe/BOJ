#include<stdio.h>


int arr[10001][3];
int main()
{
	int n,max= -1;
	scanf("%d", &n);
	scanf("%d", &arr[1][1]);
	max = arr[1][1];
	if (n == 1) {
		printf("%d", max);
		return 0;
	}
	scanf("%d", &arr[2][1]);
	arr[2][2] = arr[2][1] + arr[1][1];
	arr[2][0] = arr[1][1];
	max = arr[2][2];
	for (int i = 3; i <= n; i++) {
		scanf("%d", &arr[i][1]);
		arr[i][0] = arr[i - 1][1] > arr[i - 1][2] ? arr[i - 1][1] : arr[i - 1][2];
		if (arr[i][0] < arr[i - 1][0]) arr[i][0] = arr[i - 1][0];
		if (arr[i][0] > max) max = arr[i][0];
		arr[i][2] = arr[i][1] + arr[i - 1][1];
		if (max < arr[i][2])max = arr[i][2];
		arr[i][1] += arr[i - 1][0];
		if (max < arr[i][1])max = arr[i][1];
	}
	printf("%d", max);
	return 0;
}
