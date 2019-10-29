#include <cstdio>

int arr[1001];
int d[1001];
int main()
{
	int n;
	int m = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		scanf("%d", &arr[i]);
		for (int j = i; j >= 1; j--) {
			if (arr[i] < arr[j] && (d[j] > d[i] - 1)) {
				d[i] = d[j] + 1;
				if (m < d[i]) {
					m = d[i];
				}
			}
		}
	}
	printf("%d", m);
}
