#include<iostream>
#include<cmath>
using namespace std;
int arr[1000001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int n, b, c;
	long long cnt = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	for (int i = 1; i <= n; i++) {
		arr[i] -= b;
		cnt++;
		if (arr[i] < 0)continue;
		cnt += (long long)ceil(arr[i] / (float)c);
	}

	cout << cnt;

}
