#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void func(int n){
	int t = n % -2;
	n= n /-2;
	if(t<0){
		t=1;
		n+=1;
	}
	if(n==0){
		cout<<t;
		return;
	}
	func(n);
	cout<<t;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin>> n;
	func(n);
	return 0;
}
