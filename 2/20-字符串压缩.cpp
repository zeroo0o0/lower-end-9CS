/*
比如b不一定小于a，需要连续几个字符组成的子串才能优于所有单个字符。
也有可能先扩展出了目前最长的子串，却使得后续无法构造出更优的子串。即局部最优未必是全局最优。
t1t2...ti-1ti的长度是固定的，为i。
t1t2...ti-1的长度只有大于等于ti的长度才有可能包含ti的子串。
因此即为每加一个字符，将包含这个字符的前面字符串一分为二，
穷举所有可能组成子串的情况与直接加字符的代价进行对比。
dp[0]=a
dp[i]=dp[j-1]+b(i>0,j<=i,j\geq\left \lceil (i+1)/2 \right \rceil,且满足j~i为0~j-1的子串)
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=5005;
int dp[maxn];

void solve()
{
	int n, a, b; cin>>n>>a>>b;
	string s; cin>>s;
	dp[1]=a;
	for(int i=2;i<=s.size();i++) //len
	{
		dp[i]=dp[i-1]+a;
		string ss=s.substr(0,i);
		for(int j=(i+1)/2;j<i;j++) //分割点 
		{
			string left=s.substr(0,j); //0~j-1
			string right=s.substr(j,i-j); //warn: 从j开始  //j~i-1
			if(left.find(right)!=-1&&dp[j]+b<dp[i]) dp[i]=dp[j]+b; 	//warn dp[j] not dp[j-1] 因为长度为j
		}
	}
	cout<<dp[n]<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
