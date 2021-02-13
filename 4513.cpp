#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
    long long arr[3];
    do{
        cin>>arr[0]>>arr[1]>>arr[2];
        if(arr[0]+arr[1]+arr[2]==0)break;
        sort(arr,arr+3);
        if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]){
            cout<<"right\n";
        }
        else{
            cout<<"wrong\n";
        }
    }while(true);
    
    return 0;
}
