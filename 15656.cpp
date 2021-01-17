#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v;
int arr[10];
void func(int cnt,int idx) {
	if (cnt == m) {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for (int i=0; i<n; i++) {
		v.push_back(arr[i]);
		func(cnt+1,i);
		v.pop_back();
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
	func(0,0);
	return 0;	
}
