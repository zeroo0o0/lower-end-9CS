/*
思路分析
在上车的过程中，上车的人数有最大值，车上的原始人数加上该最大值不会超过车的最大载客量；
下车的人数有最大值，车上的原始人数不会小于该最大值
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n,w; cin>>n>>w;
	int sum=0,mn=0,mx=0; 
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		sum+=x;
		if(sum>mx) mx=sum;
		if(sum<mn) mn=sum;
	}
	/*
	解两个不等式 (注意：min<0)
	0<= min+i <=w ,0<= max+i <=w
	==>-min<= i <=w-max
	+1 because: 0<=i<=2 0,1,2 ==3
	*/
	int ans=w-mx+mn+1;
	if(ans>0) cout<<ans<<endl;
	else cout<<0<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
