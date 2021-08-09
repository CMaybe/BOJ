#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


vector<vector<long long>> m;

#define MOD 1000000007

vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b){
	vector<vector<long long>> temp(2,vector<long long>(2));
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			for(int k=0;k<2;k++){
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= MOD;
		}
	}
	return temp;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	vector<vector<long long>> ans={{{0,1},{1,0}}};
	vector<vector<long long>> t = {{1,1},{1,0}};
	long long n;
	cin>>n;
	while(n>0){
		if(n%2==1) ans = mul(t,ans);
		t=mul(t,t);
		n/=2;
	}
	cout<<ans[0][0];
	return 0;
}
