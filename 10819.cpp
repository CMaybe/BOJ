#include <iostream>
#include<algorithm>

using namespace std;

int arr[10001];
int num;
int sum(){
    int _sum=0;
    for (int i =0;i<num-1;i++){
        _sum+=abs(arr[i]-arr[i+1]);
    }
    return _sum;
}
int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int max=-1e9;
    cin>>num;
    for (int i=0; i<num; i++){
		cin>>arr[i];
	}
	sort(arr,arr+num);
    max=sum();
	while(true){
    	int idx= num-1;
    	int n=idx;
    	while(n){
    		if(arr[n-1]<arr[n]) break;
            n--;
    	}
    	if(n==0){
        	break;
    	}
    	int k=idx;
    	while (arr[n-1] >= arr[k]) k--;
        swap(arr[n-1], arr[k]); 
    	
    	while(n<idx){
    		swap(arr[n],arr[idx]);
    		n++;
    		idx--;
    	}
    	int t=sum();
        if(max<t) max=t;
	}
	cout<<max;
    return 0;
}
