#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    vector<int> vec;
	int sum=0;
	int t=0;
	for(int i =0;i<9;i++){
		cin>>t;
		vec.push_back(t);
		sum+=t;
	}
	for(int i =0;i<9;i++){
		for(int j =i+1;j<9;j++){
			t= sum-(vec[i]+vec[j]);
			if(t==100){
				int a=vec[i];
				int b=vec[j];
				sort(vec.begin(),vec.end());
				for(int i =0;i<vec.size();i++){
					if(vec[i]==a ||vec[i]==b) continue;
					cout<<vec[i]<<'\n';
				}
				return 0;
			}
		}
	}
}
