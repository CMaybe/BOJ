#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int able = 0;
string s ,t;



int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, k;
	
	cin >> n >> k;
	vector<int> v;
	for(int i = 0;i<=n;i++){
		int t = n-i;
		if(t * i < k) continue;
		v.resize(t+1,0);
		int idx;
		for(int j = 0;j<i;j++){
			idx = min(t, k);
			v[idx]++;
			k-=idx;
		}
		for(int j = t;j>=0;j--){
			for(int l =0;l<v[j];l++) cout<<'A';
			if(j>0) cout<<'B';
		}
		return 0;
	}
	cout << -1;
	return 0;
	
}
