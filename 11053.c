#include <stdio.h>

int arr[1001];
int d[1001];
int main()
{
	/*
	13
	10 20 10 50 30 20 50 10 30 20 40 30 50
	*/
	int n;
	int max = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		scanf("%d", &arr[i]);
		for (int j = i; j >= 1; j--) {
			if (arr[i] > arr[j] &&(d[j] > d[i]-1)) {
				d[i] = d[j] + 1;
				if (max < d[i]) {
					max = d[i];
				}
			}
		}
	}
	printf("%d", max);
}
