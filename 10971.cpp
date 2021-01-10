#include <iostream>
using namespace std;

int arr[11][11];
bool visit[11];
int num;
int _min=1e9; 

void dfs(int start,int from,int to,int pay,int cnt){
    if(to!=from) visit[to]=true;
	if(to==start){
	    if(cnt!=num){
	        visit[to] = false;
	        return;
	    }
		if(_min>pay){
			_min=pay;
		}
		visit[to] = false;
		return;
	}
	for(int i =0;i<num;i++){
		if(visit[i]==false && arr[to][i]!=0){
			dfs(start,to,i,pay+arr[to][i],cnt+1);
		}
	}
	visit[to] = false;
}

int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
   
    cin>>num;
    for (int i=0; i<num; i++){
    	for(int j =0;j<num;j++){
			cin>>arr[i][j];
		}
	}
	for(int i =0;i<num;i++){
		for(int j =0;j<num;j++){
			if(arr[i][j]!=0){
				dfs(i,i,j,arr[i][j],1);
			}
		}
	}
	cout<<_min;
    return 0;
}
