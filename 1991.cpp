#include <iostream>
#include<vector>
using namespace std;

typedef struct NODE{
    char left;
    char right;
}Node;


Node arr[27];

void preorder(char c){
    cout<<c;
    if(arr[c-'A'].left!='.')
        preorder(arr[c-'A'].left);
    if(arr[c-'A'].right!='.')
        preorder(arr[c-'A'].right);
}

void inorder(char c){
    if(arr[c-'A'].left!='.')
        inorder(arr[c-'A'].left);
    cout<<c;
    if(arr[c-'A'].right!='.')
        inorder(arr[c-'A'].right);
}

void postorder(char c){
    if(arr[c-'A'].left!='.')
        postorder(arr[c-'A'].left);
    if(arr[c-'A'].right!='.')
        postorder(arr[c-'A'].right);
    cout<<c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        arr[a-'A'].left=b;
        arr[a-'A'].right=c;
    }
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
    return 0;
}
