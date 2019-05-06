#include <iostream>
using namespace std;
int arr[100];

int main() {
	int n, a = 1, cnt = 1;
	cin >> n;
	while (n > a)
	{
		a += cnt * 6;
		cnt++;
	}
	cout << cnt;
}
