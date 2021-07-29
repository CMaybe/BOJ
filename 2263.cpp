#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int post[100001];
int in[100001];
int idx[100001];
void pre(int inStart,int inEnd,int postStart,int postEnd){
	if(inStart>inEnd || postStart>postEnd) return;
	int root = post[postEnd];
	cout<<root<<' ';
	pre(inStart,idx[root]-1,postStart,postStart+(idx[root]-inStart)-1);
	pre(idx[root]+1,inEnd,postStart+idx[root]-inStart,postEnd-1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>> in[i];
		idx[in[i]] = i;
	}
	for(int i = 1;i<=n;i++){
		cin>> post[i];
	}
	
	pre(1,n,1,n);
	
    return 0;
}
