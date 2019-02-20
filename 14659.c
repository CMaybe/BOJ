#include<stdio.h>

int arr[30000];

int main()
{
	int n;
	scanf("%d", &n);
	int max = -9999999999;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n-1; i++) {
		int temp = 0;
		for (int j = i+1; j < n; j++) {
			if (arr[j] > arr[i]) {
				break;
			}
			temp++;
		}
		max = max < temp ? temp : max;
	}
	printf("%d", max);
}
