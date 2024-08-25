#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,int>m;
string days[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

void solve()
{
	string s,e; int l,r; cin>>s>>e>>l>>r;
	int ans=0,cnt=0;
	int d=m[e]-m[s]+1; //warn 应该是末 -初  //warn 应该加1 
	if(d<0) d+=7;
	for(int i=l;i<=r;i++) //tuesday wednesday 84 97
		if(i%7==d%7) { //d==7 时要%7 否则WA 
			cnt++;
			ans=i;
		}
	if(cnt==0) cout<<"impossible"<<endl;
	else if(cnt==1) cout<<ans<<endl;
	else cout<<"many"<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<7;i++) m[days[i]]=i+1;
	int t; cin>>t; 
	while(t--) solve();
	return 0;
}
