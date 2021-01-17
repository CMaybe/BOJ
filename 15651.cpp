#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> v;
bool visit[9];
void func(int cnt) {
	if (cnt == m) {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for (int i=1; i<=n; i++) {
		v.push_back(i);
		func(cnt+1);
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	func(0);
	return 0;	
}
