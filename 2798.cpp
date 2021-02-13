#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int arr[101];
bool visit[101];
int k,m;
int ans=-1;

int main()
{
    vector<int> mask;
    cin>>k>>m;
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    for(int i =3;i<k;i++){
        mask.push_back(0);
    }
    
    for(int i =0;i<3;i++){
        mask.push_back(1);
    }
    
    
    do{
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=(arr[i]*mask[i]);
        }
        if(m-ans > m-sum && m>=sum){
            ans=sum;
        }
	}while(next_permutation(mask.begin(),mask.end()));
    
    cout<<ans;
    return 0;
}
