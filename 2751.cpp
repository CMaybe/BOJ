#include<cstdio>
#include<algorithm>
using namespace std;
bool desc(int a, int b) {
	return a < b;
}

int main()
{
	int arr[1001], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n,desc);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
