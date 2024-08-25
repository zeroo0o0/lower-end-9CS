#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int m1,m2,r1,r2,r3;

void solve()
{
	while(cin>>m1>>m2)
	{
		string s; cin>>s;
//		r1=r2=r3=0; // ²»±Ø 
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='A') r1=m1;
			if(s[i]=='B') r2=m2;
			if(s[i]=='C') m1=r3;
			if(s[i]=='D') m2=r3;
			if(s[i]=='E') r3=r1+r2;
			if(s[i]=='F') r3=r1-r2;
		}
		cout<<m1<<","<<m2<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
