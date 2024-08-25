#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<char,int>m;
map<string,int>ans;

void solve()
{
	int n; cin>>n;
	while(n--)
	{
		string s; cin>>s;
		string t="";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='-') continue;
			if(s[i]>='0'&&s[i]<='9') t+=s[i];
			else t+=to_string(m[s[i]]);
			if(t.size()==3) t+='-';
		}
		ans[t]++;
	}
	for(auto u:ans)
	{
		if(u.second==1) continue;
		cout<<u.first<<" "<<u.second<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	string s="ABCDEFGHIJKLMNOPRSTUVWXY"; //warn LµôÁË 
	int cnt=0,temp=2;
	for(int i=0;i<s.size();i++)
		{
			m[s[i]]=temp;
			cnt++;
			if(cnt==3) 	temp++,cnt=0;
		}
	solve();
	return 0;
}
