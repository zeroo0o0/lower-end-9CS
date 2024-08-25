#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin>>n;
	int y1=0,y2=0; //warn 放全局变量不可 被头文件用了 
	for(int i=0;i<n;i++)
	{
		int x,y; cin>>x>>y;
		if(x<0) y1++;
		else y2++;
	}
	if(y1<=1||y2<=1) cout<<"Yes";
	else cout<<"No"; //warn No not no
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
