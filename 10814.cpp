#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef struct MEM {
	int age;
	string name;
}Member;
int main()
{
	vector<Member> v;
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		string b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	stable_sort(v.begin(), v.end(), [](Member a,Member b) ->int{
		return a.age<b.age;
	});
	for (Member m : v) {
		cout << m.age << ' ' << m.name << "\n";
	}
}
