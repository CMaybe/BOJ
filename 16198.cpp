#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


vector<int> v;
int _max = -1;
void func(int e){
	if(v.size()<=2){
		_max = max(e,_max);
		return;
	}
    for(int i = 1;i<v.size()-1;i++){
		int sum = v[i-1] * v[i+1];
		int t = v[i];
		auto it = v.begin(); 
		v.erase(it + i);
        func(sum+ e);
		v.insert(it + i,t);
    }
}


int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
	int n,s,t;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> t;
		v.push_back(t);
    }
    for(int i = 1;i<v.size()-1;i++){
		int sum = v[i-1] * v[i+1];
		int t = v[i];
		auto it = v.begin(); 
		v.erase(it + i);
        func(sum);
		v.insert(it + i,t);
    }
	cout<<_max;
	return 0;
}
