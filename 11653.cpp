#include<iostream>
using namespace std;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin>>n;
	if(n==1){
	    return 0;
	}
	for(int i = 2;n!=1;i++){
        while(n%i == 0){
	        cout<<i<<'\n';
            n/=i;
        }
	}	
}
