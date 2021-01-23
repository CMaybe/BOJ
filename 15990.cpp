#include <cstdio>
int mod = 1000000009;
int arr[100001][4];
int main() {
	int n, t;
	arr[1][1] = arr[2][2] = arr[3][1]=arr[3][3]=arr[3][2]=1;
	for (int i = 4; i <= 100000; i++) {
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % mod;
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % mod;
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % mod;
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", (((arr[n][1] + arr[n][2]) % mod) + arr[n][3]) % mod);
	}
	return 0;
}
