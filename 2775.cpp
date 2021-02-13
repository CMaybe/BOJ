#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int arr[20][20];
int main()
{
    int n,k,t;
    for(int i = 0;i<20;i++){
        arr[0][i]=i;
    }
    for(int i=1;i<20;i++){
        for(int j = 1;j<20;j++){
            for(int k=1;k<=j;k++){
                arr[i][j]+=arr[i-1][k];
            }
        }
    }
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>k>>n;
        cout<<arr[k][n]<<'\n';
    }
    
   
    return 0;
}
