#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
set<int,greater<int>>s;
map<int,int>m;

void solve()
{
	int n; cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	int cnt=1;
	for(auto u:s) 
	{
		m[u]=cnt;
		cnt++;
	}
	for(int i=0;i<n;i++) cout<<m[a[i]]<<" ";
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
