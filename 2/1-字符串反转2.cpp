#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	string str;
	while(getline(cin,str))
	{
		stringstream ss(str);
		string s;
		vector<string>v;
		while(ss>>s) v.push_back(s);
		for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";	
		cout<<endl;	
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
