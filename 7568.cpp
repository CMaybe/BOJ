#include <iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;

int arr[51][3];
int main()
{
    int n;
    
    cin >>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(arr[i][0]>arr[j][0] && arr[i][1]>arr[j][1]) arr[j][2]++;
        }
    }
    
    for(int i = 0;i<n;i++){
        cout<<arr[i][2]+1<<' ';
    }
    
    return 0;
}
