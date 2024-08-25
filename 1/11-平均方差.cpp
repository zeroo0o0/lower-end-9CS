#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		int a[n+5]={0};
		double sum=0.0;
		for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
		double ave=sum/n;
		double sum2=0;
		for(int i=0;i<n;i++)
			sum2+=(a[i]-ave)*(a[i]-ave);
		double ans=floor(sum2/n);
		cout<<ans<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
