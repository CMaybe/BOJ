#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


long long temp;
long long pre,post;

long arr[4000001];

void func(long long a,long long p){
	if (p % a > 0){
		func(p%a,a);
		temp = post;
		post = pre - (p/a)*post;
		pre = temp;
	}
	else{
		pre = 0;
		post = 1;
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,k;
	long p = 1000000007;
	cin>>n>>k;
	arr[0]=arr[1]=1;
	for(int i = 2;i<=n;i++){
		arr[i] = (arr[i-1]*i)%p;
	}
	long t = (arr[k]*arr[n-k]) % p;
	func(t,p);
	long result = ((arr[n] % p)*(post%p))%p;
	if(result<0)result+=p;
	cout<<result;
	return 0;
}
