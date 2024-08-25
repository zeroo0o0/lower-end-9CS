#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int t; cin>>t; cout<<t<<endl;
	while(t--)
	{
		int n; cin>>n;
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			cout<<s<<" ";
		}
		cout<<endl;
	}	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1; 
	while(t--) solve();
	return 0;
}
