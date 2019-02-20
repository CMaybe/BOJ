#include<stdio.h>

int n, boj[1000];
char input[1001];

int main()
{
	scanf("%d %s", &n, input);
	for (int i = 1; i < n; i++) {
		boj[i] = 1e9;
		for (int j = 0; j < i; j++) {
			if ((input[j] == 'B'&&input[i] == 'O' || input[j] == 'O'&&input[i] == 'J' || input[j] == 'J'&&input[i] == 'B')
				&& boj[j] + (i - j)*(i - j) < boj[i]) {
				boj[i] = boj[j] + (i - j)*(i - j);
			}
		}
	}
	printf("%d", (boj[n - 1] != 1e9) ? boj[n - 1] : -1);
}
