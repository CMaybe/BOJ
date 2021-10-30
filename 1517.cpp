#include <iostream>
#include <vector>
using namespace std;

using lld = long long int;
lld cnt = 0;

void merge(vector<int> &v,lld s, lld m, lld e){
	lld a = s, b= m + 1,idx = 0;
	vector<int> t(e-s+1);
	while(a!=m+1 && b!=e+1){
		if(v[a] <= v[b]){
			t[idx] = v[a];
			a++;
			cnt += b - m - 1;
		}
		else{
			t[idx] = v[b];
			b++;
		}
		idx++;
	}
	if(a!=m+1){
		cnt += static_cast<long long int>((e-m)*(m-a+1));
		while(a!=m+1) t[idx++] = v[a++];
	}
	else while(b!=e+1) t[idx++] = v[b++];
	for(int i = 0;i<idx;i++) v[s+i] = t[i];
}

void mergesort(vector<int> &v,lld s, lld e){
	if(s==e) return;
	mergesort(v,s,(s+e)/2);
	mergesort(v,(s+e)/2+1,e);
	merge(v, s, (s+e)/2, e);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i<n;i++) cin >> v[i];
	mergesort(v, 0, n-1);
	
	cout<<cnt;
	
	return 0;
	
}
