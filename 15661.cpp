#include <iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;

int arr[21][21];

int a=0;
int b=0;
int n,cnt = 1;
int _min = 1e9;
void Combination(vector<int> ori, vector<int> s, int idx, int depth)
{
 
	if(depth!=0){
		a=0,b=0;
		for(int j = 0;j<n;j++){
			if(std::binary_search(s.begin(), s.begin() + depth, j)){
				for(int t : std::vector<int>(s.begin(), s.begin() + depth)){
					a+=arr[j][t];
				}
			} 
			else{
				for(int k = 0; k < n;k++){
					if(std::binary_search(s.begin(), s.begin() + depth, k) == false){
						b+=arr[j][k];
					}
				}
			}
		}
		_min = _min > abs(a-b) ? abs(a-b) : _min;
	}
	
    if (depth>=n/2) return;
    else
    {
        for(int i = idx; i < ori.size(); i++)
        {
            s[depth] = ori[i];
            Combination(ori, s, i + 1, depth + 1);
        }
    }
}

int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	cin>>n;
	vector<int> v;
	vector<int> s;
	for(int i=0; i<n; i++) v.push_back(i);
	
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	s.resize(n);
	Combination(v,s,0,0);
	
	cout<<_min;


	return 0;
}
