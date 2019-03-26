#include<stdio.h>

int dp[1001][10];
int main() {
	int n;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <10; i++) {
		sum += dp[n][i];
	}
	printf("%d", sum % 10007);

}
