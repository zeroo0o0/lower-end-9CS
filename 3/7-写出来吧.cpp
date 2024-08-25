#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string str[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
map<char,string>m;
void solve()
{
	string s; cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++) sum+=s[i]-'0';;
	s=to_string(sum);
	for(int i=0;i<s.size();i++)
		cout<<m[s[i]]<<" ";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<10;i++) m[i+'0']=str[i];
	solve();
	return 0;
}
