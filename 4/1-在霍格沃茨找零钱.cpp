#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long

void solve()
{
	int g,s,k; char a,b; cin>>g>>a>>s>>b>>k;
	int sum=g*17*29+s*29+k;
	cin>>g>>a>>s>>b>>k;
	int pay=g*17*29+s*29+k;
	int d=pay-sum;
	if(d<0) cout<<"-", d=-d;
	g=d/(17*29); d%=(17*29);
	s=d/29; //warn /29 not /17 
	k=d%29; //warn %29 not %17 
	cout<<g<<"."<<s<<"."<<k; 
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
