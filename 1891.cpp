#include <string>
#include <cmath>
#include <iostream>
#include <utility>
using namespace std;

long d;
string s;
long long dx, dy, x ,y;


string pos2str(long long dep, long long cx, long long cy){
	if (dep==0) return "";
	long long ct = 1ll<<(dep-1);
	if(cx >= ct && cy < ct){
		return "1" + pos2str(dep-1,cx-ct,cy);	
	}
	else if(cx < ct && cy < ct){
		return "2" + pos2str(dep-1, cx, cy);	
	}
	else if(cx < ct && cy >= ct){
		return "3" + pos2str(dep-1,cx,cy-ct);	
	}
	else if(cx >= ct && cy >= ct){
		return "4" + pos2str(dep-1,cx-ct,cy-ct);	
	}
	return "";
}

pair<long long, long long> str2pos(int idx, long long x1, long long y1, long long x2, long long y2){
	if(idx==d){
		return make_pair(x1,y1);
	}
	int n = s[idx] - '0';
	if(n==1){
		return str2pos(idx + 1, (x1+x2)/2, y1, x2,(y1+y2)/2);
	}
	else if(n==2){
		return str2pos(idx + 1, x1, y1, (x1+x2)/2,(y1+y2)/2);
	}
	else if(n==3){
		return str2pos(idx + 1, x1, (y1+y2)/2, (x1+x2)/2, y2);
	}
	else if(n==4){
		return str2pos(idx + 1, (x1+x2)/2, (y1+y2)/2, x2,y2);
	}
	return make_pair(x1,y1);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	cin >> d >> s;
	cin >> x >> y;
	long long t = 1ll << d;
	pair<long long , long long> p = str2pos(0,0,0,t,t);
	p.first += static_cast<long long>(x);
	p.second -= static_cast<long long>(y);
	if(p.first >= 0 && p.first < t && p.second >=0 && p.second < t){
		cout << pos2str(d, p.first, p.second);
	}
	else{
		cout<<"-1";
	}
	
	return 0;
	
}
