#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
static const int MAXN=1e5+10;
struct Node {
    int v, w;
    bool operator<(const Node &r) const { //因为默认是大根堆 
        return w > r.w;
    }
};
vector<Node> g[MAXN];
long long dist[MAXN];
bool vis[MAXN];
int pre[MAXN];
int n, m;
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<Node> Q;
    Q.push(Node{1, 0});
    while (!Q.empty())
    {
        Node t = Q.top();
        Q.pop();
        int u = t.v;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].v;
            if (!vis[v] && dist[v] > dist[u] + g[u][i].w)
            {
                dist[v] = dist[u] + g[u][i].w;
                Q.push(Node{v, dist[v]});
                pre[v]=u;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
//    for(int i=0;i<7;i++) cout<<dist[i]<<endl; 
    if(dist[n]==0x3f3f3f3f3f3f3f3f) puts("-1");
    else
    {
        vector<int> ans;
        int t=n;
        while(pre[t])
        {
            ans.push_back(t);
            t=pre[t];
        }
        printf("1");
        for(int i=ans.size()-1;i>=0;i--)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

