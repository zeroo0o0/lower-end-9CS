#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
int a[maxn][maxn], mv[maxn];

void solve()
{
	int n,m; cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			char c; cin>>c;//warn : 用int读01001  一次读一行
			if(c-'0'>0)  a[i][j]=1;
			if(a[i][j]>0) mv[j]++; //warn  if判断 
		}

	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<m;j++)
			if(mv[j]-a[i][j]>0) cnt++;	
				
		if(cnt==m) 
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
