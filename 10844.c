#include<stdio.h>

long long arr[101][11] = { 0, };


int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
    for(int i=1;i<10;i++)
        arr[1][i] =1;
	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 1][1] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i-1][j + 1]) % 1000000000;
		}
		arr[i][9] = arr[i - 1][8] % 1000000000;
	}
	for (int i = 0; i <= 9; i++) {
		sum += (arr[n][i]%1000000000);
        sum%=1000000000;
	}
	printf("%d", sum);
}
