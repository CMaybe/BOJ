#include<iostream>
#include<cmath>
#include <iomanip> 

using namespace std;
#define PI 3.141593
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	double r;
	cin>>r;
	cout<<setprecision(10);
	cout<<fixed;
	double s1 = r*r*M_PI;
	double s2 = r*r*2;
	cout<<s1<<'\n'<<s2;
	
	
	
	
}
