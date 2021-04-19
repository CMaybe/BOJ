#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int arr[21][21];
int n;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	vector<int> v;
	
	cin>>n;
	for(int i =1;i<=n;i++){
	    for(int j = 1;j<=n;j++){
	        cin>>arr[i][j];
	    }
	}
	for(int i = 1;i<=n/2;i++){
	    v.push_back(0);
	}
	
	for(int i = 1;i<=n/2;i++){
	    v.push_back(1);
	}
	int s1=0,s2=0;
	int _min = 1e9;
	do{
	    for(int i =1;i<=n;i++){
	        for(int j = 1;j<=n;j++){
	            if(i==j) continue;
	            else if(v[i-1]+v[j-1]==0) s1+=arr[i][j];
	            else if(v[i-1]+v[j-1]==2) s2+=arr[i][j];
	        }
	    }
	    _min = min(_min,(int)abs(s1-s2));
	    s1=0;
	    s2=0;
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<_min;
}
