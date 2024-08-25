#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char checks[]={'1','0','X','9','8','7','6','5','4','3','2'};

void solve()
{
	string s;
	while(cin>>s&&s!="-1")
	{
		int sum=0;
		for(int i=0;i<17;i++) sum+=w[i]*(s[i]-'0');
		char c=checks[sum%11];
		if(c==s[17]) cout<<1<<endl;
		else cout<<0<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
