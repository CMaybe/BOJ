#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int arr[10002];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int s,e,sum,cnt;
	s=e=1;
	sum=cnt=0;
	
	while(e<=n+1){
		if(sum>=m) sum -= arr[s++];
		else sum = sum + arr[e++];
		if(sum==m)cnt++;
	}
	cout <<cnt;
    return 0;
}

