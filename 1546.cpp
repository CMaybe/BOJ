#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,t, sum = 0, max = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		sum += t;
		if (t > max)max = t;
	}
	cout << sum / (double)max * 100 / n;
}
