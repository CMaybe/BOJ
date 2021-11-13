#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int n;
long long int m, ans;
vector<int> p, visit;

void func(int idx, int t){
	if(t==0){
		long long int factor = 1;
		for(int i : visit) factor*=p[i];
		if(visit.size()%2==1) ans+=m/factor;
		else ans -= m/factor;
		return;
	}
	for(int i = idx+1;i<n;i++){
		visit.push_back(i);
		func(i, t-1);
		visit.pop_back();
	}
}
int main()
{
	
	cin >>n >>m;
	p.resize(n);
	for(int i = 0;i<n;i++) cin >> p[i];
	for(int i = 1;i<=n;i++) func(-1, i);
	
	cout << ans;
	return 0;
	
}
