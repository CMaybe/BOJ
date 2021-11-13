#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct POINT{
	double x;
	double y;
	double z;
	POINT(double x=0, double y=0, double z=0): x(x),y(y),z(z){}
	POINT operator-(const POINT& rhs){
		return POINT(x-rhs.x, y-rhs.y, z-rhs.z);
	}
	double operator*(const POINT& rhs){
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}
	POINT operator&(const POINT& rhs){
		return POINT(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
	}
}Point;

double len(Point p){
	return sqrt(p*p);
}

int main()
{
	Point p[3];
	for(int i = 0;i<3;i++){
		cin>>p[i].x>>p[i].y>>p[i].z;
	}
	Point a = p[1]-p[0];
	Point b = p[2]-p[0];
	Point c = p[2]-p[1];
	cout<<fixed;
	cout.precision(6);
	if((a*b) * (a*c)<=0) cout<<len(a&b)/len(a);
	else cout<< min(len(b),len(c));
	return 0;
}
