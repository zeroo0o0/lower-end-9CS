#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		int a[n]={0};
		for(int i=0;i<n;i++) cin>>a[i];
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(a[j]<a[i]) ans++;
		cout<<ans<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
