#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main()
{
	int n;
	long long int c, ans=-1;
	
	cin >> n >> c;
	vector<long long int> v(n);
	for(int i = 0;i<n;i++) cin>>v[i];
	sort(v.begin(), v.end());
	
	long long int s = 1;
	long long int e = v[v.size()-1] - v[0];
	while(s<=e){
		long long int m = (s+e)/2;
		long long int cnt = 1;
		long long int d = v[0];
		for(int i = 1;i<n;i++){
			if(v[i]-d >=m ){
				cnt++;
				d = v[i];
			}
		}
		if(cnt < c) e = m-1;
		else{
			s = m+1;
			ans = max(m,ans); 
		}
	}
	cout << ans;
}
