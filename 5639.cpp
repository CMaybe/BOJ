#include <iostream>
#include<vector>
using namespace std;

typedef struct NODE{
    int right;
    int left;
}Node;

Node tree[1000001];

void postorder(int n){
    if(tree[n].left>0)
        postorder(tree[n].left);
    if(tree[n].right>0)
        postorder(tree[n].right);
    cout<<n<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int root;
    int n;
    cin>>root;
    int idx=0;
    while(cin>>n){
        int cur = root;
        
        while(true){
            if(n<cur){
                if(tree[cur].left>0) cur = tree[cur].left;
                else{
                    tree[cur].left=n;
                    break;
                }
            }
            else{
                if(tree[cur].right!=0)cur=tree[cur].right;
                else{
                    tree[cur].right=n;
                    break;
                }
            }
        }
    }
    
    postorder(root);
    
    return 0;
}
