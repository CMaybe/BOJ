#include<cstdio>

int main()
{
	int n;
	int arr[31] = { 0, };
	arr[0] = 1;
	arr[2] = 3;
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 2] * 3;
		for (int j = 2; j <= i; j+=2) {
			arr[i] += arr[i - j] * 2;
		}
	}
	printf("%d", arr[n]);
	return 0;
}
