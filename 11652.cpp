#include<iostream>
#include<vector>
#include<map>
using namespace std;
int arr[1000001];
map<long,int,greater<long>> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long n, a = 0, max = -1, idx=0;
	cin >> n;
	while (n--)
	{
		cin >> a;
		if (m.find(a)==m.end()) {
			m.insert(make_pair(a, 1));
		}
		else {
			m.find(a)->second += 1;
		}
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second >= max) {
			max = i->second;
			idx = i->first;
		}
	}
	cout << idx;
}
