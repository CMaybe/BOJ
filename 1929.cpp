#include <iostream>

int arr[1000001];

using namespace std;

int main()
{
    arr[0]=arr[1]=1;
    for(int i = 2;i*i<1000001;i++){
        for(int j = 2;i*j<1000001;j++){
            arr[i*j]=1;
        }
    }
    int a,b;
    cin >>a>>b;
    for(int i =a;i<=b;i++){
        if(arr[i]==0) cout<<i<<'\n';
    }
    
    return 0;
}
