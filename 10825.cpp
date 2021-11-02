#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct NODE{
	string name;
	int kor;
	int eng;
	int math;
}Node;

bool comp(const Node& a, const Node& b){
	if(a.kor == b.kor){
		if(a.eng == b.eng){
			if(a.math == b.math){
				return a.name < b.name;
			}
			return a.math > b.math; 
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,a,b,c;
	vector<Node> v;
	string s;
	cin >> n;
	for (int i = 0;i<n;i++){
		cin >> s >> a >> b >> c;
		v.push_back({s,a,b,c});
	}
	sort(v.begin(), v.end(), comp);
	
	for(int i = 0;i<n;i++){
		cout<<v[i].name<<'\n';
	}
	
	return 0;
	
}
