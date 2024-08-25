/*
设dis[v]表示v以上的点到达这个点的最大权值(肯定是它的祖先中的某个点到这个点) 类似于最大连续累加和 
当往下走(x,y)这条边的时候,设其权值为w,以及到目前为止走过的最大权值和cur 如果cur<0,那么就
不要之前的路径了,直接加上cur（***because a一定是>=1的）。 否则连着之前的路径加上去就好。 这样就能贪心地求出来dis[v]了 
如果dis[x]>a[x]那么它以及它下面的所有节点都要删掉(因为要从叶子节点开始删) 
如果dis[x]<=a[x]那么就可以保留这个点了。用总数减去最多可以保留的点的个数。就是最少需要删掉的个数了。
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int maxn=1e5+5;
//int vis[maxn]; 好像用不上，用pre记录父结点就够了 
vector<vector<pii>>e(maxn);
int cnt, a[maxn];

void dfs(int u, int now, int pre)
{
	if(now>a[u]) return;
	cnt++;
	for(auto t:e[u])
	{
		int v=t.first, w=t.second;
		if(v==pre) continue;
		dfs(v,max(0LL,now+w),u);//[Error] no matching function for call to 'max(int, long long int)'
	}
}

void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) 
	{
		int u=i+1, v, w; cin>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0,-1);
	cout<<n-cnt;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
