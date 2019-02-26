#include<stdio.h>

int arr[10001];
int v[101];
int main()
{
	int n, k, tmp, max = -1;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	arr[0] = 1;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i - v[j] < 0) continue;
			arr[i] += arr[i - v[j]];
		}
	}
	printf("%d", arr[k]);
}
