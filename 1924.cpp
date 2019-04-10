#include<string>
#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string w[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int m, d, sum = 0;
	cin >> m >> d;
	for (int i = 1; i < m; i++) {
		sum += arr[i];
	}
	sum += d;
	cout << (w[(sum - 1) % 7]);
}
