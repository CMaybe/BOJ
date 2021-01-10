#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[50];
int mask[50];
int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n;
    bool flag = true;
    while(flag){
        cin>>n;
        if(n==0)  break;
        memset(mask,0,sizeof(mask));
        for(int i=0;i<6;i++){
            mask[i]=1;
        }
        for (int i=0; i<n; i++){ 
            cin>>arr[i];
        }
    	do{
            for(int i =0;i<n;i++){
                if(mask[i]==1){
                    cout<<arr[i]<<' ';
                }
            }
            cout<<'\n';
    	}while(std::prev_permutation(mask,mask+n));
    	cout<<'\n';
    }
   
    return 0;
}
