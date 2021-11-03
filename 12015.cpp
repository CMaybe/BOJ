#include <iostream>
#include <vector>

using namespace std;

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n,cnt = 0;
	cin >>n;
	vector<int> v;
	v.push_back(-1e9);
	int temp;
	for(int i = 0;i<n;i++){
		cin>> temp;
		if(temp>v.back()){
			v.push_back(temp);
			cnt++;
		}
		else{
			auto t = lower_bound(v.begin(), v.end(), temp);
			*t = temp;
		}
	}
	cout<<cnt;
	
	return 0;
	
}
