#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<int,int,greater<int>>m;

void solve()
{
	int a,b;
	while(cin>>a>>b&&(a||b)) m[a]+=b;
	while(cin>>a>>b&&(a||b)) m[a]+=b;
	for(auto u:m)  //warn：若b最后==0  不输出 
		if(u.second!=0) cout<<u.first<<" "<<u.second<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
