#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
char s1[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char s2[]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
map<char,char>m;

void solve()
{
	string s;
	while(getline(cin,s)&&s!="ENDOFINPUT")
	{
		if(s=="START"||s=="END") continue;
		for(int i=0;i<s.size();i++)
			if(s[i]>='A'&&s[i]<='Z') s[i]=m[s[i]];
		cout<<s<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i=0;i<26;i++) m[s1[i]]=s2[i];
	solve();
	return 0;
}
