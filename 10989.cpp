#include<iostream>
using namespace std;
int arr[10001];
int main()
{
	int n,a=0,max=-1;
	cin >> n;
	while (n--)
	{
		cin >> a;
		arr[a]++;
		if (max < a)max = a;
	}
	for (int i = 1; i <= a; i++) {
		if (!arr[i]) continue;
		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}
}
