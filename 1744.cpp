#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int able = 0;
string s ,t;



int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	int cnt1=0, cnt2 = 0;
	cin >> n;	
	std::vector<long long int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	bool flag= false;
	sort(v.begin(), v.end(), greater<long long int>());
	long long int sum = 0;
	for(int i = 0;i<n;i++){
		if(v[i]==1 || v[i+1]==1) sum+=v[i];
		else if(v[i]>0){
			if(i!=n-1 && v[i+1] > 0){
				sum+=v[i]*v[i+1];
				i++;
			}
			else sum+=v[i];
		}
		else if(v[i]==0){
			if((n-1-i) % 2 == 1){
				i++;
			}
		}
		else{
			if(flag == false){
				sort(v.begin()+i, v.end());
				flag = true;
				i--;
			}
			else if(i==n-1) sum += v[i];
			else{ 
				sum+=v[i]*v[i+1];
				i++;
			}
		}
	}

	cout<<sum;
	return 0;
	
}
