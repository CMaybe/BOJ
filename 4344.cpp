#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int arr[1001];
	cout.setf(ios::fixed);
	cout.precision(3);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n,c,t, max = -1;
	double sum = 0, avg;

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
			sum += arr[j];
		}
		avg = sum / n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (avg < arr[j]) sum++;
		}
		cout << sum/n*100 << "%\n";
		sum = 0;
	}
}
