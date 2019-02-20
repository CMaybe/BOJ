#include<stdio.h>

int arr[100];
int result[100];
char vec[100];
int ra[3]; //0 : blue, 1 : red, 2 : green
int main()
{
	int money;
	int n;
	scanf("%d", &money);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %c", &arr[i], &vec[i]);
		if (vec[i] == 'L') {
			for (int j = 0; j < arr[i] - 1; j++) {
				result[j]++;
			}
		}
		else {
			for (int j = arr[i]; j < 100; j++) {
				result[j]++;
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		ra[result[i] % 3]++;
	}
	printf("%.2f\n%.2f\n%.2f\n", (double)money / 100 * ra[0], (double)money / 100 * ra[1], (double)money / 100 * ra[2]);

}
