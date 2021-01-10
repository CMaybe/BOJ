#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[12];
vector<char> syms;
int cnt[4];
int _max=-1e9;
int _min=1e9;
int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<4;i++){
        cin>>cnt[i];
    }
    for(int i=0;i<cnt[0];i++){
        syms.push_back('+');
    }
    for(int i=0;i<cnt[1];i++){
        syms.push_back('-');
    }
    for(int i=0;i<cnt[2];i++){
        syms.push_back('*');
    }
    for(int i=0;i<cnt[3];i++){
        syms.push_back('/');
    }
    sort(syms.begin(),syms.end());
    do{
        int result=arr[0];
        for(int i=1;i<n;i++){
            switch(syms[i-1]){
                case '+':
                    result+=arr[i];
                    break;
                    
                case '-':
                    result-=arr[i];
                    break;
                    
                case '*':
                    result*=arr[i];
                    break;
                    
                case '/':
                    result/=arr[i];
                    break;
            }
        }
        if(_max < result)_max=result;
        if(_min > result)_min=result;
    }while(std::next_permutation(syms.begin(),syms.end()));
    
    cout<<_max<<'\n';
    cout<<_min;
    
    return 0;
}
