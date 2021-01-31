#include <iostream>
#include<string>
#include<set>
using namespace std;


int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    auto cmp=[](string a, string b){
        if(a.length() == b.length()){
            return a<b;
        }
        return a.length() < b.length();
    };

    set<string,decltype(cmp)> s(cmp);
    int n;
    string t;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>t;
        s.insert(t);
    }
    
    for (string t : s) {
        cout << t << '\n';
    }

    return 0;
}
