#include <iostream>
#include<algorithm>
using namespace std;

int arr[10001];


int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int num;
    cin>>num;
    for (int i=0; i<num; i++){
		cin>>arr[i];
	}
	int idx= num-1;
	int n=idx;
	while(n){
		if(arr[n-1]<arr[n]) break;
        n--;
	}
	if(n==0){
		cout<<-1;
		return 0;
	}
	int k=idx;
	while (arr[n-1] >= arr[k]) k--;
    swap(arr[n-1], arr[k]); 
	
	while(n<idx){
		swap(arr[n],arr[idx]);
		n++;
		idx--;
	}
	for (int i=0; i<num; i++){
		cout<<arr[i]<<' ';
	}
    return 0;
}
