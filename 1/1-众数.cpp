#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		map<int,int>m;
		for(int i=0;i<n;i++)
		{
			int x; cin>>x;
			m[x]++;
		}
		map<int,int,greater<int>>m2;
		for(auto u:m)
		{
			if(u.second<=m2.begin()->first) continue;
			m2.insert({u.second,u.first});  //warn  u.second相同时 后进盖住第一个 
		//	cout<<u.first<<" "<<u.second <<endl;
		}
		int mx=m2.begin()->second;
		cout<<mx<<endl;
	} 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
