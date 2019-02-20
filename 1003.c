#include<stdio.h>
int main()
{
	int n,a,arr[42] = { 1,0 };
	for (int i = 2; i < 42; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	for (scanf("%d", &n); n > 0; n--) {
		scanf("%d", &a);
		printf("%d %d\n", arr[a], arr[a+1]);
	}
}
