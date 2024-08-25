#include<bits/stdc++.h>
using namespace std;

void solve()
{
//	cin.ignore(); //warn： 必须忽略换行符 
	string s;
	getline(cin,s);
	stringstream ss(s);
	string buf;
	while(ss>>buf)
	{
		reverse(buf.begin(),buf.end());
		cout<<buf<<" ";
	}
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0); //warn 不关流同步  则一点超时 
	int t; cin>>t; 
	cin.ignore();  //warn：cin和getline之间必须忽略换行符 
	while(t--) solve();
	return 0;
}
