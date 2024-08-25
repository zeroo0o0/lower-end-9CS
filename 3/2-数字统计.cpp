#include<bits/stdc++.h>
using namespace std;
#define int long long
map<char,int>m;

void solve()
{
	string s; cin>>s;
	for(int i=0;i<s.size();i++) m[s[i]]++;
	for(auto u:m) cout<<u.first<<":"<<u.second<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
