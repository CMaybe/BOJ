#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<unsigned int> v;

int func(int row){
	if(row==n){
		int sum = 0;
		for(int i = 0;i<n;i++){
			int t = 0;
			for(int c : v){
				if(c & (1<<i)) t++;
			}
			sum += min(t,n-t);
		}
		return sum;
	}
	int t1 = func(row+1);
	v[row] = ~v[row];
	int t2 = func(row+1);
	return min(t1,t2);
}

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	v.resize(n, 0);
	for(int i = 0;i<n;i++){
		string s;
		cin >> s;
		for(int j = 0;j<n;j++){
			v[i] |= (static_cast<unsigned int>(s[j]=='T') << j);
		}
	}
	cout<<func(0);
	return 0;
	
}
