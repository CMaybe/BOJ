#include <iostream>
#include<cstring>
using namespace std;
int d[201][201];

int f(int n,int k){
    if(k==1) return 1;
    if(d[n][k]!=-1) return d[n][k];
    int c= 0;
    for(int i = 0;i<=n;i++){
        c=(c+f(n-i,k-1)) %1000000000;
    }
    d[n][k]=c;
    return c;
}

int main() {
    memset(d, -1, sizeof(d));
    int n=0,k,ans=0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cout<<f(n,k);

	return 0;
}



