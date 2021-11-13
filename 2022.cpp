#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
	double x, y, c;
	cin >> x >> y >> c;
	double s = 0;
	double e = min(x, y);
	double m = 0;
	cout<<fixed;
	cout.precision(3);
	while(s<=e){
		m = (s+e)/2;
		double d = -sqrt(x*x-m*m)/sqrt(y*y-m*m)*c + sqrt(x*x-m*m);
		if(d > c) s = m+0.0001;
		else{
			e = m-0.0001;
		}
	}
	cout << m;
}
