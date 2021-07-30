#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[500000];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
	int n,t,c;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cin>>t;
	for(int i = 0;i<t;i++){
		cin>>c;
		if(binary_search(arr,arr+n,c)) cout<<"1 ";
		else cout<<"0 ";
	}
	
    return 0;
}
