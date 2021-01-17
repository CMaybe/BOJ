#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v;
bool visit[10];
int arr[10];
void func(int cnt) {
	if (cnt == m) {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for (int i=0; i<n; i++) {
	    if(visit[i]) continue;
		v.push_back(arr[i]);
		visit[i]=true;
		func(cnt+1);
		v.pop_back();
		visit[i]=false;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	func(0);
	return 0;	
}
