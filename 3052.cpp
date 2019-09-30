#include<cstdio>

int main()
{
	int arr[42] = { 0, };
	int cnt = 0,t;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &t);
		t %= 42;
		if (arr[t] == 0) {
			cnt++;
			arr[t] = 1;
		}
	}
	printf("%d", cnt);
}
