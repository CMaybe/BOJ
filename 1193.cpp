#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,t;
	cin>>n;
	int i; 
	for(i = 0;i<=100000;i++){
	    if(i*i+i>=2*n){
	        i=i-1;
	        break;
	    }
	}
	t=(n-(i*i+i)/2);
	
	if(i%2==1) cout<<t<<'/'<<i+2-t;
	else cout<<i+2-t<<'/'<<t;
}
