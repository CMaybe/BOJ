#include<stdio.h>

int arr[100001];

int main()
{
	int n;
	int sum=0;
	int max = -1e9;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] <= sum + arr[i]) {
			sum += arr[i];
		}
		else {
			sum = arr[i];
		}
		if (max < sum) {
			max = sum;
		}
	}
	printf("%d", max);

}
