#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int t,n,len;
    cin>>t;
	while(t--){
		int arr[2][100001];
		int d[3][100001];
		cin>>n;
		for(int i = 0;i<2;i++){
			for(int j = 1;j<=n;j++){
				cin>>arr[i][j];
			}
		}
		for(int j = 1;j<=n;j++){
			d[0][j] = arr[0][j] + max(d[1][j-1],d[2][j-1]);
			d[1][j] = arr[1][j] + max(d[0][j-1],d[2][j-1]);
			d[2][j] = max(d[0][j-1],max(d[1][j-1],d[2][j-1]));
		}
    	cout<<max(d[0][n],max(d[1][n],d[2][n]))<<'\n';
	}
	
    return 0;
}
