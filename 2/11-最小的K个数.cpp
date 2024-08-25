#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve()
{
	int n,k; cin>>n>>k;
	set<int>s;
	for(int i=0;i<n;i++) 
	{
		int x; cin>>x;
		s.insert(x);
	}
	int cnt=0;
	for(auto u:s) 
	{
		cout<<u<<" "; cnt++;
		if(cnt==k) break;
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
