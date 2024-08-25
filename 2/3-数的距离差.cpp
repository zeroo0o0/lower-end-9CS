#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int mx=0,mn=1e5;
void solve()
{
	int n; cin>>n; //warn 
	int a[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	int ans=1e6;
	int mind=1e6;
	for(int i=0;i<n;i++)
	{
		int dis=abs(abs(a[i]-mx)-(a[i]-mn));
		if(dis<mind||dis==mind&&a[i]<ans)
		{
			ans=a[i];
			mind=dis;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
