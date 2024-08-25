#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int cnt(string s)
{
	int temp=0;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		temp+=(s[i]-'a')*pow(26,i); //warn: s[i]-'a' not s[i]-'0'
	return temp;
}

void solve()
{
	string s1,s2; cin>>s1>>s2;
	int ans=cnt(s1)+cnt(s2);
	string s="";
	while(ans>0)
	{
		s+=(ans%26)+'a';
		ans/=26;
	}
	reverse(s.begin(),s.end()); //warn: µ¹×ªÒ»ÏÂ 
	cout<<s<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
