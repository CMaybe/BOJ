#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool flag[300001];
int lim[300001];

typedef struct GEM{
	int value;
	int weight;
}Gem;

bool cmp(const Gem& a, const Gem& b){
	if(a.weight == b.weight){
		return a.value < b.value;
	}
	return a.weight < b.weight;
	
}


int main()
{
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<Gem> v(n);
	vector<int> lim(k);
	priority_queue<int> pq;
	for(int i = 0;i<n;i++){
		cin>> v[i].weight >> v[i].value;
	}
	for(int i = 0;i<k;i++){
		cin >> lim[i];
	}
	sort(v.begin(), v.end(), cmp);
	sort(lim.begin(), lim.end());
	int idx = 0;
	long long int sum = 0;
	for(int i = 0;i<k;i++){
		while(idx<n && v[idx].weight <= lim[i])	pq.push(v[idx++].value);
		if(!pq.empty()){
			sum+=static_cast<long long int>(pq.top());
			pq.pop();
		}

	}
	
	cout << sum;
	return 0;
	
}
