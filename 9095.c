#include<stdio.h>
int arr[100001];
int main(void)
{
	int n, a;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	scanf("%d", &n);
	for (int j = 0; j < n; j++) {
		scanf("%d", &a);
		if (arr[a] != 0) {
			printf("%d\n", arr[a]);
		}
		else {
			for (int i = 4; i <= a; i++) {
				arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
			}
			printf("%d\n", arr[a]);
		}
	}
}
