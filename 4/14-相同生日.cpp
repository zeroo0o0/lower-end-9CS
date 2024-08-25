#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define pii pair<int,int>
map<pii,vector<string>>m;

void solve()
{
	int n; cin>>n;
	while(n--)
	{
		string s; int x,y; cin>>s>>x>>y;
		m[{x,y}].push_back(s);
	}
	for(auto u:m)
	{
		cout<<u.first.first<<" "<<u.first.second<<" ";
		for(auto v:u.second) cout<<v<<" ";
		cout<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
