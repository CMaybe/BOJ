#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;

using ll = long long;
	
typedef struct NODE{
	ll num;
	string s;
}Node;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	queue<Node> q;
	ll s,t;
	cin>> s>>t;
	if(s==t){
		cout<<0;
		return 0;
	}
	q.push({s * s,"*"});
	q.push({s + s,"+"});
	q.push({s - s,"-"});
	q.push({s / s,"/"});
	while(q.empty()==false){
		Node p = q.front();
		q.pop();
		if(p.num==t){
			cout<<p.s;
			return 0;
		}
		if(p.num==0)continue;
		if(p.num!=1 && p.num * p.num <= t)q.push({p.num * p.num,p.s+'*'});
		if(p.num + p.num <= t)q.push({p.num + p.num,p.s+"+"});

	}
	cout<<-1;
	
	return 0;
	
}
