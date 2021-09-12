#include<iostream>
using namespace std;

char arr[36];
int a,b;
void func(int n){
	if(n==0) return;
	func(n/b);
	cout<<arr[n%b];
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>a>>b;

	
	for(int i = 0;i<10;i++){
		arr[i] = '0' + i;
	}
	for(int i = 0;i<26;i++){
		arr[i+10] = 'A' + i;
	}
	
	
	func(a);
	return 0;
	
}
