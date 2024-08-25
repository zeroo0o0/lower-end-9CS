// 找规律 
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n; cin>>n;
	int a[n+5][n+5]={0};
	a[1][1]=1;
	for(int i=2;i<=n;i++) a[i][1]=a[i-1][1]+i-1; //第i行第1列
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n-(i-1);j++)
			a[i][j]=a[i][j-1]+i+j-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-(i-1);j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
