#include <iostream>

using namespace std;

int gcd(int a, int b){
	int r = a % b;
	if (r == 0)
		return b;
	else
		return gcd(b, r);
}
int main(int argc, char** argv) {
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<(a*b)/gcd(a,b)<<'\n';
    }
}
