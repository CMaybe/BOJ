#include<stdio.h>

int main()
{
	int arr[8],i;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	if (arr[0] < arr[1]) {
		for (i = 1; i < 7; i++) {
			if (arr[i] > arr[i + 1]) {
				printf("mixed");
				break;
			}
		}
		if(i==7)
			printf("ascending");
	}
	else
	{
		for (i = 1; i < 7; i++) {
			if (arr[i] < arr[i + 1]) {
				printf("mixed");
				break;
			}
		}
		if(i==7)
			printf("descending");
	}
}
