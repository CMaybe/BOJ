#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
using ll = long long;

ll gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	ll s,ans;
	
	cin>>n>>s;
	
	vector<ll> vec(n);
	for(int i =0;i<n;i++){
		cin>>vec[i];
	}
	
	for(int i =0;i<n;i++){
		vec[i] = static_cast<ll>(abs(s-vec[i]));
	}
	ans = vec[0];
	for(int i = 0;i<n;i++){
		ans = (vec[i]>ans) ? gcd(vec[i],ans) : gcd(ans,vec[i]);
	}
	cout<<ans;
	
	
	
	return 0;
}
