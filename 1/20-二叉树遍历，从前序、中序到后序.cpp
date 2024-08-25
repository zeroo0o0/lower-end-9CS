#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(string pre,string in)
{
	if(pre.empty()) return;
	char root=pre[0];
	int pos=in.find(pre[0]);
	pre.erase(0,1);
	string leftpre=pre.substr(0,pos);
	string leftin=in.substr(0,pos);
	string rightpre=pre.substr(pos);
	string rightin=in.substr(pos+1);
	solve(leftpre,leftin);
	solve(rightpre,rightin);
	cout<<root;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n; 
	while(cin>>n&&n!=0)
	{
		string pre, in;
		cin>>pre>>in;
		solve(pre,in);
		cout<<endl;
	}
	return 0; 
}
