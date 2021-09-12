#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

	
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,t;
	priority_queue<int,vector<int>,greater<int>> p1;
	priority_queue<int> p2;
	cin>> n;
	for(int i = 0;i<n;i++){
		cin>>t;
		if(p2.empty()) p2.push(t);
		else{
			if(p1.size()<p2.size())	p1.push(t);
			else p2.push(t);
			
			if(p2.top() > p1.top()){
				int a = p2.top();
				int b = p1.top();
				p1.pop();
				p2.pop();
				p2.push(b);
				p1.push(a);
			}
		}
	
		cout<<p2.top()<<'\n';
	}
	
	return 0;
	
}
