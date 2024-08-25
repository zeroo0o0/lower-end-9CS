#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int a[]={100,20,10,5,1};

void solve()
{
	int n; cin>>n;
	int ans=0;
	for(int i=0;i<5;i++)
	{
		int x=a[i];
		while(n>=x) ans+=n/x, n%=x; //warn: >= not >
		if(n==0) break;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
