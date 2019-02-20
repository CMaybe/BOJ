#include<stdio.h>

void primeNum(int arr[], int n)
{
	int j = 0, cnt = 0;
	for (int i = 0; i < n; i++) {

		for (j = 2; j <= arr[i] / 2; j++) {
			if (arr[i] % j == 0) break;
		}
		if (j == (arr[i] / 2 + 1))cnt++;
	}
	printf("%d", cnt);
}

int main()
{
	int n, arr[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	primeNum(arr, n);

}
