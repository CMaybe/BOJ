#include<iostream>
#include<string>
using namespace std;
 
int n,k;
int ans;
string set[51];
bool visit[26];
 
int find()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
		int j = 0;
        for (j = 0; j < set[i].length(); j++)
        {
            if (visit[set[i][j] - 'a'] == false) break;
        }
        if (j == set[i].length()) cnt++;
    }
    return cnt;
}

void func(int start, int cnt)
{
    if (cnt == k - 5) {
        int _max = find();
        if (ans < _max) ans = _max;
        return;
    }
    for (int i = start; i < 26; i++)
    {
        if (visit[i]) continue;
        visit[i] = true;
        func(i+1, cnt+1);
        visit[i] = false;
    }
    return;
}
 
int main()
{
    string s;
    cin >> n >> k;
 
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s = s.substr(4, s.length()-8);
        set[i] = s;
 
    }
 
    if (k == 26) ans = n;
    else if (k > 4)
    {
        visit['a' - 'a'] = true;
        visit['n' - 'a'] = true;
        visit['t' - 'a'] = true;
        visit['i' - 'a'] = true;
        visit['c' - 'a'] = true;
 
        func(0,0);
    }
 
    cout << ans;
 
    return 0;
}
