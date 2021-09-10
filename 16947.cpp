#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdlib>

using namespace std;


int arr[3001];
int result[3001];
vector<vector<int>> v;
int ans = -1;
void dfs(int n,int len){
	if(ans>=0) return;
	arr[n] = len;
	for(int t : v[n]){
		if(len - arr[t] != 1 && arr[t]!=-1){
			ans=arr[t];
			break;
		}
		if(arr[t] == -1) dfs(t,len+1);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
	
	int n,a,b;
	cin >> n;
	v.resize(n+1);
	for(int i = 0;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1;i<=n;i++){
		memset(arr,-1,sizeof(arr));
		ans = -1;
		dfs(i,0);
		result[i] = ans;
	}
	int p = *min_element(result +1, result+n);
	for(int i = 1;i<=n;i++){
		cout<<result[i]-p<<' ';
	}
	
	
	
	
	
	
	
	return 0;
	
}
