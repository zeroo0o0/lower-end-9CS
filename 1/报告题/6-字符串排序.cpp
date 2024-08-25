#include<bits/stdc++.h>
using namespace std;
multimap<int,string>mp;

void solve()
{
	int n,m; cin>>n>>m; //warn cin
	for(int i=0;i<m;i++)
	{
		string s; cin>>s;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			 	if(s[j]<s[i]) cnt++;
		}
		mp.insert({cnt,s}); //warn mÖØÃûÁË 
	}
	for(auto u:mp)
		cout<<u.second<<endl; 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
