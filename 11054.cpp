#include<cstdio>

int d1[1001], d2[1001], a[1001];

int main() {
	int n, m=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d1[i] = 1;
		d2[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d1[i] < d1[j] + 1) {
				d1[i] = d1[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (m < d1[i] + d2[i]) m = d1[i] + d2[i];
	printf("%d", m - 1);
	return 0;
}
