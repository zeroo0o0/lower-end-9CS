#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		map<string,int>m;
		for(int i=0;i<2*n-1;i++) //warn 2*n-1
		{
			string s; cin>>s;
			m[s]++;
		}
		for(auto u:m)
			if(u.second%2!=0)
			{
				cout<<u.first<<endl;
				break;
			}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
