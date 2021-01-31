#include <iostream>
#include<stack>
#include<vector>
using namespace std;
int A[1000001];
int F[1000001];
stack<int> s,ans;
vector<int> v;
    
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int n,m;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>A[i];
        F[A[i]]++;
    }
    

    for(int i =n;i>=1;i--){
        while(s.empty() == false && F[s.top()]<=F[A[i]]){
            s.pop();
        }
        
        if(s.empty()){
            ans.push(-1);
        }
        else{
            ans.push(s.top());
        }
        s.push(A[i]);
    }
    
    while(ans.empty()==false){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}
