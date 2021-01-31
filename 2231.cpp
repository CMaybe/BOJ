#include <iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;





int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    
    int n;
    
    cin>>n;
    int t = n;
    int len = 0;
    while(t){
        t/=10;
        len++;
    }
    
    for(int i =n-(9*len);i<n;i++){
        t=i;
        int sum = i;
        while(t){
            sum+=t%10;
            t/=10;
        }
        if(sum==n){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
   

    return 0;
}
