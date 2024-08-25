/*
思路
1.很经典的动态规划问题，也就是不断地计算最佳结果，从而得到当前的最佳结果！
2.动态规划最重要的就是找到状态转移方程dp[I]=max(dp[i],dp[j]+1)
3.用2的方法我们可以找到第i+1枚导弹为最后一发的最多能够拦截多少发，那么第i+2枚同理是最大值
4.最后我们遍历找出dp中的最大值就可以得到我们的最多拦截导弹数了
如何理解动态规划： 
简单来说，就是把大问题化为小问题，找到小问题的解决方案，合成大问题的解决方案，
记录小问题的最优解决方案，以便于回溯寻找，降低时间复杂度。
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int k; cin>>k;
	vector<int>h(k),dp(k); 
	for(int i=0;i<k;i++)
	{
		cin>>h[i];
		dp[i]=1;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<i;j++)
			if(h[j]>=h[i]) dp[i]=max(dp[i],dp[j]+1); 
	int mx=0; 
	for(int i=0;i<k;i++) mx=max(dp[i],mx);  //warn：dp【i】是必须有i的，但如果太大就不一定是最优解 
	cout<<mx;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
