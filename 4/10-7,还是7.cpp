#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int m,n=7; cin>>m;
	string s=to_string(n);
	for(int i=1;i<=m;i++)
	{
		if(i%n==0)
		{
			cout<<i<<endl;
			continue;
		}
		string temp=to_string(i);
		if(temp.find(s)!=-1) cout<<i<<endl; //warn ÕÒ²»µ½·µ»Ø-1 
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
