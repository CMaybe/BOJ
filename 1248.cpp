#include <iostream>
#include<vector>
#include <cmath>
#include<algorithm>
#include<string>
using namespace std;

char arr[11][11];
int n;

void dfs(std::vector<int> v, int depth){
	if(depth>=n){
		for(int i = 0;i<depth;i++){
			std::cout<<v[i]<<' ';
		}
		exit(0);
		return;
	}
	std::vector<int> temp = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
	for(int i=0;i<=depth;i++){
		if(arr[i][depth]=='-'){
			temp.erase(remove_if(temp.begin(),temp.end(),[=](int t){
				int sum=0;
				for(int k = i;k<depth;k++) sum+=v[k];
				return sum+t>=0;
			}),temp.end());
			
		}
		else if(arr[i][depth]=='+'){
			temp.erase(remove_if(temp.begin(),temp.end(),[=](int t){
				int sum=0;
				for(int k = i;k<depth;k++) sum+=v[k];
				return sum+t<=0;
			}),temp.end());;
		}
		else if(arr[i][depth]=='0'){
			temp.erase(remove_if(temp.begin(),temp.end(),[=](int t){
				int sum=0;
				for(int k = i;k<depth;k++) sum+=v[k];
				return sum+t!=0;
			}),temp.end());
		}
	}
	for(int t:temp){
		v[depth]=t;
		dfs(v,depth+1);
	}
}


int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin>>n;
	cin>>s;
	vector<vector<char>> v;
	vector<int> ans;
	ans.resize(n);
	int idx = 0;
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			arr[i][j]= s[idx++];
		}
	}
	if(arr[0][0]=='-'){
		for(int i =-10;i<0;i++){
			ans[0]=i;
		dfs(ans,1);
		}
	}
	else if(arr[0][0]=='+'){
		for(int i =1;i<=10;i++){
			ans[0]=i;
		dfs(ans,1);
		}
	}
	else if(arr[0][0]=='0'){
		ans[0]=0;
		dfs(ans,1);
	}
	
	return 0;
}
