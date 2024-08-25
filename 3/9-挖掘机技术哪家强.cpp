#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<int,int>
map<int,int>m;
vector<pii>v;

bool cmp(pii a, pii b)
{
	return a.second>b.second;
}

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		int x,y; cin>>x>>y;
		m[x]+=y;
	}
	for(auto u:m) v.push_back({u.first,u.second});
	sort(v.begin(),v.end(),cmp);
	cout<<v[0].first<<" "<<v[0].second<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
