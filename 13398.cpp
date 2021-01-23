#include <iostream>
#include<cstring>
using namespace std;
int arr[100001][2];
int main() {
    memset(arr,0,sizeof(arr));
    int n=0,max=-1e9;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++){
	    cin>>arr[i][0];
	}
	max=arr[1][1]=arr[1][0];
	for (int i = 2; i <= n; i++)
	{
	    arr[i][1]= arr[i-1][1]+arr[i][0] > arr[i-1][0] ?arr[i-1][1]+arr[i][0] : arr[i-1][0];
        max=arr[i][1]>max ?arr[i][1]:max;
    	arr[i][0]=arr[i][0] > arr[i-1][0]+arr[i][0] ? arr[i][0]:arr[i-1][0]+arr[i][0];
        max=arr[i][0]>max ?arr[i][0]:max;
       
	}


	cout<< max;
	return 0;
}
