#include<stdio.h>
int arr[16][2];
int dp[16];

int main()
{
	int n, max = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &arr[i][0], &arr[i][1]);
		if (arr[i][0]+i > n+1) arr[i][1] = 0;
		arr[i][1] += dp[i];
		for (int j = i + arr[i][0]; j <= n; j++) {
			if (dp[j] < arr[i][1]) {
				dp[j] = arr[i][1];
			}
		}
		if (arr[i][1] > max) max = arr[i][1];

	}
	printf("%d", max);

}
