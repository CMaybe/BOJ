#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 1; j < t; j++) {
			if (t % j == 0) v.push_back(j);
		}
		int sum = 0;
		while (!v.empty())
		{
			sum += v.back();
			v.pop_back();
		}
		if (sum == t)cout << "Perfect\n";
		else if (sum < t)cout << "Deficient\n";
		else cout << "Abundant\n";

	}

	return 0;
}
