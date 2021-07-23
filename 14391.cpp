#include <iostream>
#include <algorithm>
using namespace std;

int arr[4][4];
bool visit[30];

int main(int argc, char* argv[]) {
	int _max = -1;
	int m,n;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	for(int i =0;i<(1<<(n*m));i++){
		int sum = 0;
		for(int j = 0;j<n;j++){
			int temp=0;
			for(int k =0;k<m;k++){
				int idx = j*m + k;
				if((i &(1<<idx))==0){
					temp=temp*10 + arr[j][k];
				}
				else{
					sum+=temp;
					temp=0;
				}
			}
			sum+=temp;
		}
		
		for(int j = 0;j<m;j++){
			int temp=0;
			for(int k =0;k<n;k++){
				int idx = k*m + j;
				if((i &(1<<idx))!=0){
					temp= temp*10 + arr[k][j];
				}
				else{
					sum+=temp;
					temp=0;
				}
			}
			sum+=temp;
		}
		// cout<<i<<'\t'<<sum<<'\n';
		_max = std::max(_max,sum);
		
	}
	cout<<_max;
	
	
	return 0;
}
