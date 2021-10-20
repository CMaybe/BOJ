#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
vector<int> v;
bool visit[10001];
 
void func(int n)
{
    string s = to_string(n);
    string t1 = s;
    string t2 = s;
    t1.pop_back();
    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());
    if (s.length() == 1)
    {
        v.push_back(n);
        v.push_back(stoi(s + s));
    }
    else
    {
        v.push_back(stoi(s + t2));
        v.push_back(stoi(s + t1));
    }
}
 
int main()
{
    for (int i =1;i<=10000;i++){
        func(i);
	}
    sort(v.begin(), v.end());
	
    int a, b;
    cin >>a>>b;
	
    visit[1] = true;
    for (int i = 2; i <= 10000; i++){
        if (visit[i]) continue;
        for (int j=i+i;j<=10000;j+=i) visit[j] = true;
    }
	
    for (int i=0; i<v.size()-2;i++){
        bool flag = true;
        if (v[i] >= a && v[i] <= b){
            for (int j=1; j*j<= v[i]; j++){
                if ((visit[j] == false) && (v[i] % j == 0)) {
                    flag = false;
                    break;
                }
            }
            if (flag) cout<< v[i] << '\n'; 
        }
    }
    cout << -1;
    
    return 0;
}
