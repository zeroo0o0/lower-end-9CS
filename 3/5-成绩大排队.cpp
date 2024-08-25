#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node{
	string s1,s2; int score;
};

bool cmp(node a, node b)
{
	return a.score>b.score;
}

void solve()
{
	int n; cin>>n;
	vector<node>v(n);
	for(int i=0;i<n;i++) cin>>v[i].s1>>v[i].s2>>v[i].score;
	sort(v.begin(),v.end(),cmp);
	cout<<v[0].s1<<" "<<v[0].s2<<endl;
	cout<<v[v.size()-1].s1<<" "<<v[v.size()-1].s2<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
