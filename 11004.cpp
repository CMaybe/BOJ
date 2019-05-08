#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v;
	int n, k, a;
	cin >> n >> k;
	while (n--)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cout << v[k - 1];

}
