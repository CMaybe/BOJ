#include<stdio.h>


int arr[301][4];
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%d", &arr[1][1]);
	scanf("%d", &arr[2][1]);
	arr[2][2] = arr[2][1] + arr[1][1];
	for (int i = 3; i <= n; i++) {
		scanf("%d", &arr[i][1]);
		arr[i][2] = arr[i][1] + arr[i - 1][1];
		arr[i][1] += arr[i - 2][1] < arr[i - 2][2] ? arr[i - 2][2] : arr[i - 2][1];
	}
	int max = arr[n][2] > arr[n][1] ? arr[n][2] : arr[n][1];
	printf("%d", max);

}
