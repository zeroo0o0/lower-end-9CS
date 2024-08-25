#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 

void solve()
{
	int n; cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt=1, ans=0;
	for(int i=1;i<n;i++) 
	{
		if(a[i]>a[i-1]) cnt++;
		else
		{
//			cnt=1; //warn 取max再更新cnt 
			ans=max(ans,cnt); 
			cnt=1;
		}
		if(i==n-1) ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
