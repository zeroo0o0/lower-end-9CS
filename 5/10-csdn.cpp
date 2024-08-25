#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int n,cnt;
int a[N+10];
vector<pair<int,int> > g[N+10];

void dfs(int x,long long now,int pre){
    if (now>a[x]) return;
    cnt++;
    int len = g[x].size();
    for (int i = 0;i < len;i++){
        int y = g[x][i].first;
        int w = g[x][i].second;
        if (y==pre) continue;
        dfs(y,max(1LL*0,now)+w,x);  
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 2;i <= n;i++){
        int x = i,y,w;
        cin >> y >> w;
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }
    dfs(1,0,-1);
    cout<<n-cnt<<endl;
	return 0;
}

