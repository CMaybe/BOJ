#include<stdio.h>
int arr[1001] = { 0,1,2,0 };
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}
	printf("%d", arr[n] % 10007);
}
