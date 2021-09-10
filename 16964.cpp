#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> ans;

bool check[100001];


void dfs(int x) {
    if (check[x] == true) {
        return;
    }
    check[x] = true;
    ans.push_back(x);
    for (int y : v[x]) {
        if (check[y] == false) {
            dfs(y);
        }
    }
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	int n;
	int a,b;
	cin >> n;
	v.resize(n+1);
	vector<int> ex = vector<int>(n+1); 
	vector<int> idx = vector<int>(n+1);
	for(int i =0;i<n-1;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		cin>>ex[i];
		idx[ex[i]] = i;
	}
	for(int i  = 1;i<=n;i++){
		sort(v[i].begin(),v[i].end(),[&idx](int a, int b)-> bool{
			return idx[a] < idx[b];
		});
	}
	dfs(1);
	for(int i = 1;i<=n;i++){
		
		if(ex[i]!=ans[i-1]){
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
	
}
