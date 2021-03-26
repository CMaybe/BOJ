#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct ITEM{
    int weight;
    int value;
}Item;

int n,k;
int dp[101][100001];

vector<Item> items;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >>n>>k;
	for(int i = 0;i<n;i++){
	    int w,v;
	    cin>>w>>v;
	    items.push_back({w,v});
	}
	
	for(int i = 0;i<n;i++){
	    for(int j =0;j<=k;j++){
	        if(i==0){
	            if(items[i].weight<=j){
	                dp[i][j]=items[i].value;
	            }
	            continue;
	        }
	        if(items[i].weight<=j){
                dp[i][j] = max(dp[i-1][j],items[i].value+dp[i-1][j-items[i].weight]);
            }
	        else{
	            dp[i][j] = dp[i-1][j];
            }
	    }
	}
	cout<<dp[n-1][k];

}
