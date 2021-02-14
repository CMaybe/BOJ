#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


void insert(vector<long long>& heap,long long data){
    if(heap.size()==1){
        heap.push_back(data);
        return;
    }
    
    heap.push_back(data);
    int cur = heap.size()-1;
    int parent = cur/2;
    while(parent>0){
        if(abs(heap[parent])>abs(heap[cur]) ||
                (abs(heap[parent])==abs(heap[cur]) &&
                  heap[parent]>heap[cur])){
            swap(heap[parent],heap[cur]);
            cur = parent;
            parent = cur/2;
            continue;
        }
        break;
        
    }
}

long long _delete(vector<long long>& heap){
    if(heap.size()==1) return 0;
    long long _min = heap[1]; 
    heap[1]=heap.back();
    heap.pop_back();
    int cur = 1;
    int left= cur*2;
    int right = cur*2+1;
    
    while(left<heap.size()){
        if(right<heap.size()){
            if(abs(heap[left])>abs(heap[right]) ||
                (abs(heap[left])==abs(heap[right]) &&
                  heap[left]>heap[right])){
                if(abs(heap[right])>abs(heap[cur]) ||
                (abs(heap[right])==abs(heap[cur]) &&
                  heap[right]>heap[cur])) break;
                swap(heap[right],heap[cur]);
                cur = right;
                left = cur *2;
                right = cur*2+1;
            }
            else{
                if(abs(heap[left])>abs(heap[cur])||
                (abs(heap[left])==abs(heap[cur]) &&
                  heap[left]>heap[cur])) break;
                swap(heap[left],heap[cur]);
                cur = left;
                left = cur *2;
                right = cur*2+1;
            }
        }
        else{
            if(abs(heap[left])>abs(heap[cur])||
                (abs(heap[left])==abs(heap[cur]) &&
                  heap[left]>heap[cur])) break;
            swap(heap[left],heap[cur]);
            cur = left;
            left = cur *2;
            right = cur*2+1;
        }
    }
    
    return _min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    vector<long long> v;
    v.push_back(-1);
    cin>>n;
    long long cmd;
    for(int i = 0;i<n;i++){
        cin>>cmd;
        if(cmd==0){
            cout<<_delete(v)<<'\n';
        }
        else{
            insert(v,cmd);
        }
    }
    
    return 0;
}
