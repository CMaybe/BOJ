#include<stdio.h>
long long arr[100001] = { 0,1,1,1,2,2,3,4,5,7,9, };

int main()
{
	int n,t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (arr[t]) {
			printf("%lld\n", arr[t]);
		}
		else {
			for (int j = 10; j <= t; j++) {
				if (arr[j]) continue;
				arr[j] = arr[j - 1] + arr[j - 5];
			}
			printf("%lld\n", arr[t]);
		}
	}
}
