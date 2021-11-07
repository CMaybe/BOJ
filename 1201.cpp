#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>

using namespace std;


int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if((m+k-1<=n) && (n<=m*k)){
		vector<int> v(n);
		for(int i = 0;i<n;i++) v[i] = i+1;
		int idx = 0;
		for(int i = 1;i<=m;i++){
			int temp = min(idx+k, n-m+i);
			reverse(v.begin() + idx, v.begin()+temp);
			idx = temp;
		}
		for(int e : v) cout<<e<<' ';
	}
	else{
		cout << -1;
	}
	
	return 0;
	
}
