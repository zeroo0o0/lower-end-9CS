#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int maxn=1e5+5;
struct node{
	int v,dis; //顶点，距离 
	bool operator<(node b) const  //warn***const 必须有 //***必须有bool 
	{
		return dis>b.dis;
	}
};

int dis[maxn], vis[maxn];
vector<vector<node>>e(maxn);

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n-1;i++) 
	{
		int u,v,w; cin>>u>>v>>w;
		e[u].push_back(node{v,w}); //warn***权值也要存呀 
		e[v].push_back(node{u,w}); //***warn {u,w}
	} 
	memset(dis,0,sizeof(dis));
	dis[0]=0; //warn***初始化 
	priority_queue<node>q;
	q.push(node{0,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto temp:e[u])
		{
			int v=temp.v;
			if(!vis[v]&&dis[v]<dis[u]+temp.dis)
			{
				dis[v]=dis[u]+temp.dis; //***warn 更新啊 
				q.push(node{v,dis[v]});
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		if(dis[i]>ans) ans=dis[i];
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
