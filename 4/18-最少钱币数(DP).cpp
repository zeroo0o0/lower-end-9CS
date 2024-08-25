#include<bits/stdc++.h> //DP 背包问题 
using namespace std;
#define endl '\n'
const int INF=0x3f3f3f3f;
int m;

void solve()
{
	int n; cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end()); //升序 
	int dp[m+1];
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<n;j++)
		{
			if(v[j]>i) break;
			dp[i]=min(dp[i-v[j]]+1,dp[i]);  //dp 
		}	
	if(dp[m]!=INF) cout<<dp[m]<<endl; //warn dp[m]
	else cout<<"Impossible"<<endl; //***warn： I 大写 
} 

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>m&&m) solve();
	return 0;
}
