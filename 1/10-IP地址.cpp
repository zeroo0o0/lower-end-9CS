#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int cnt(int x)
{
	int ans=0;
	while(x>0)
	{
		int temp=x%2;
		if(temp==1) ans++;
		x/=2;
	}
	return ans;
}

void solve()
{
	int t; cin>>t;
	while(t--)
	{
		int a,b,c,d; char e,f,g;
		cin>>a>>e>>b>>f>>c>>g>>d;
		int sum=0;
		sum+=cnt(a)+cnt(b)+cnt(c)+cnt(d);
		cout<<sum<<endl;
	} 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
