#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int n,s,cnt=0;
bool flag[2000001];
int arr[100001];
void func(int idx,int sum){
    flag[sum]=true;
    for(int i = 1;i+idx<n;i++){
        func(idx+i,sum+arr[i+idx]);
    }
}


int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++){
        func(i,arr[i]);
    }
    for(int i = 1;i<=2000000;i++){
		if(flag[i]==false){
			cout<<i;
			break;
		}
	}
	return 0;
}
