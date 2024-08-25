#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	string s,s1;
	while(cin>>s>>s1)
	{
		int cnt=count(s.begin(),s.end(),'?'); //?数量 
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='?')
			{
				cnt--;
				ans+=('9'-s1[i])*pow(10,cnt);
				continue;
			}
			if(s[i]==s1[i]) continue;
			if(s[i]<s1[i]) break;
			if(s[i]>s1[i]) 
			{
				ans+=pow(10,cnt);
				break; //warn:结束了 don't forget break
			}
		}
		cout<<ans<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
