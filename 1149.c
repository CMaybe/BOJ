#include<stdio.h>
#define R 0
#define G 1
#define B 2
#define MAX 3

int arr[1001][4];
int main()
{
	int n, min = 1e9;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i][R]);
		arr[i][R] += arr[i - 1][B] > arr[i - 1][G] ? arr[i - 1][G] : arr[i - 1][B];
		scanf("%d", &arr[i][G]);
		arr[i][G] += arr[i - 1][B] > arr[i - 1][R] ? arr[i - 1][R] : arr[i - 1][B];
		scanf("%d", &arr[i][B]);
		arr[i][B] += arr[i - 1][R] > arr[i - 1][G] ? arr[i - 1][G] : arr[i - 1][R];
	}
	min = arr[n][R];
	if (arr[n][G] < min) min = arr[n][G];
	if (arr[n][B] < min) min = arr[n][B];

	printf("%d", min);
}
