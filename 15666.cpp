#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<int> v;
int arr[10];
bool ex[10001];
int l=0;
void func(int cnt,int idx) {
	if (cnt == m) {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for (int i=idx; i<l; i++) {
		v.push_back(arr[i]);
		func(cnt+1,i);
		v.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int t;

	for(int i=0;i<n;i++){
	    cin>>t;
	    if(ex[t]==false){
	        arr[l]=t;
	        ex[t]=true;
	        l++;
	    }
	}
	sort(arr,arr+l);
	func(0,0);
	return 0;	
}
