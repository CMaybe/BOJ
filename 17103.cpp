#include<iostream>
#include<cstring>
#include<cmath>
#define SIZE 1000001
using namespace std;

bool arr[SIZE];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	memset(arr, true, sizeof(arr));
	arr[0] = arr[1] = false;
	for (int i = 2; i <= (int)sqrt(SIZE); i++){
		for (int j = i + i; j < SIZE; j += i) {
			arr[j] = false;
		}
	}

	int n,t;
	cin >> n;
	while (n--) {
		cin >> t;
		int cnt = 0;
		for (int i = 2; i <= t / 2; i++) {
			if (arr[i] && arr[t - i]) cnt++;
		}
		cout << cnt << "\n";
	}

}
