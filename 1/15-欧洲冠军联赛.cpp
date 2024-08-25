#include<bits/stdc++.h> //考点： 结构体 
using namespace std;
#define endl '\n'
struct node{
	int score,win;
};
#define pii pair<string,node>
bool cmp(pii a,pii b)
{
	if(a.second.score>b.second.score) return true; //为真则 a在b前面 
	if(a.second.score==b.second.score&&a.second.win>b.second.win) return true;
	else return false;
}

void solve()
{
	map<string,node>m;
	for(int i=0;i<12;i++)
	{
		string a,b,c; int x,y; cin>>a>>x>>b>>y>>c;
		if(y!=x)
		{
			if(y>x) swap(a,c),swap(x,y); //让左边赢 
			if(m.find(a)==m.end()) m[a].score=3; //!m[a] map<string,int>m; 才能用 
			else m[a].score+=3;
			m[a].win+=x-y; //warn +=not = 
			m[c].win+=y-x; //warn  a,c 才是 
		}
		else
		{
			if(m.find(a)==m.end()) m[a].score=1;
			else m[a].score+=1;
//			m[a].win+=x-y; //加0不用更新 
			if(m.find(c)==m.end()) m[c].score=1;
			else m[c].score+=1;
		}
	}
	vector<pii>v;
	for(auto u:m)	v.push_back({u.first,u.second});
	sort(v.begin(),v.end(),cmp);
//	for(int i=0;i<v.size();i++)   //warn 删测试数据 
//		cout<<v[i].first<<" "<<v[i].second.score<<" "<<v[i].second.win<<endl;
	for(int i=0;i<2;i++) cout<<v[i].first<<" ";
	cout<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t; cin>>t; 
	while(t--) solve();
	return 0;
}
