#include<stdio.h>
int arr[10001];
void selfNum(int n)
{
	if (arr[n] || n>10000) return;
	int sum = n;
	while (n!=0)
	{
		sum += n % 10;
		n /= 10;
	}
	selfNum(sum);
	arr[sum] = 1;
}
int main()
{
	for (int i = 1; i <= 10000; i++) {
		selfNum(i);
	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i])printf("%d\n", i);
	}
}
