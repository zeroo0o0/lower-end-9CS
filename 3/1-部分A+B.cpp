#include<bits/stdc++.h>
using namespace std;
#define int long long

int cnt(int x,int y)
{
	x=abs(x);
	string s=to_string(x);
	char c=y+'0';
	int cnt=count(s.begin(),s.end(),c);
	string t="";
	for(int i=0;i<cnt;i++) t+=c;
	stringstream ss(t);
	int num=0; //warn***局部变量一定要 初始化
	ss>>num;
//	cout<<t<<" "<<num<<endl;
	return num;
}

void solve()
{
	int a,da,b,db; cin>>a>>da>>b>>db; ////warn: 会溢出int
	int ans=cnt(a,da)+cnt(b,db);
	cout<<ans<<endl;
}

signed main() //warn: signed
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
