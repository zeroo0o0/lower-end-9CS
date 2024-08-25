#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans, sum[105];

void solve()
{
	int n; cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int temp=sum[i-1]+(j-i+1-(sum[j]-sum[i-1]))+sum[n]-sum[j]; //i前面算1 i和j之间算0 j后面算1
			ans=max(ans,temp);
		}
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
