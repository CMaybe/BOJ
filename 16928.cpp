#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int arr[101];
int ladder[101],snake[101];

queue<int> q;

int dp[101];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int m,n,t1,t2;
	cin>>n>>m;
	for(int i = 0;i<m+n;i++){
	    cin>>t1>>t2;
	    arr[t1]=t2;
	}
	memset(dp, -1, sizeof(dp));
	q.push(1);
	dp[1] = 0;
	while (!q.empty())
	{
	    int t = q.front();
	    q.pop();
	    for(int i = 1;i<=6;i++){
	        int next = t+i;
	        if(next>100)continue;
	        
	        if(arr[next]!=0){
	            next=arr[next];
	        }
	        if(dp[next]==-1){
	            dp[next]=dp[t]+1;
	            q.push(next);
	        }
	    }
	}
	
	cout<<dp[100];
	
}
