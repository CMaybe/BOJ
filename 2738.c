#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arr[101][101];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int h = y; h < y + 10; h++) {
			for (int w = x; w < x + 10; w++) {
				arr[h][w] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			ans += arr[i][j];
		}
	}

	printf("%d\n", ans);

}
