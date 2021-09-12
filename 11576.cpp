#include <cmath>
#include<iostream>
using namespace std;

long long a,b;

void func(long long n){
	if(n==0) return;
	func(n/b);
	cout<<n%b<<' ';
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin>>a>>b;
	long long t;
	long long num = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin>>t;
		num += t*pow(a,(n-1-i));
	}
	func(num);
	
	return 0;
	
}
