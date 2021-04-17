#include<iostream>
using namespace std;
int arr1[1001];
int arr2[1001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int x,y;
	for(int i =0;i<3;i++){
	    cin>>x>>y;
	    arr1[x]++;
	    arr2[y]++;
	}
	for(int i = 1;i<=1000;i++){
	    if(arr1[i]==1){
	        cout<<i<<' ';
	    }
	}
	
	for(int i = 1;i<=1000;i++){
	    if(arr2[i]==1){
	        cout<<i;
	    }
	}
	
	
}
