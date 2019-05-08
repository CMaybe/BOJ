#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (pair<int,int> p : v) {
		cout << p.first << ' ' << p.second << "\n";
	}

}
