#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 

void solve()
{
	int n; 
	while(cin>>n&&n)
	{
		string s; cin>>s;
		int sum1=0,sum2=0;
		int pos=0;
		while(s.find("ab",pos)!=-1) pos=s.find("ab",pos)+1,sum1++;
		pos=0;
		while(s.find("ba",pos)!=-1) pos=s.find("ba",pos)+1,sum2++;
		cout<<sum1-sum2<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
