#include<bits/stdc++.h>   //考察结构体 
using namespace std;
#define endl '\n'
struct node{ 
	vector<int>v;  //不行，交上去报错  // 
	//
	int score;
};
map<string,node>m;
#define pii pair<string,node> //warn pair<string,node>
vector<pii>v;   
int a[]={0,25,18,15,12,10,8,6,4,2,1};

bool cmp1(pii a,pii b)
{
	if(a.second.score!=b.second.score) return a.second.score>b.second.score; //warn 优化 
	auto va=a.second.v; auto vb=b.second.v; 
	for(int i=1;i<=100;i++)
	{
		if(count(va.begin(),va.end(),i)!=count(vb.begin(),vb.end(),i)) 
			return count(va.begin(),va.end(),i)>count(vb.begin(),vb.end(),i);
	}
}

bool cmp2(pii a,pii b)
{
	auto va=a.second.v; auto vb=b.second.v; 
	if(count(va.begin(),va.end(),1)!=count(vb.begin(),vb.end(),1)) 
		return count(va.begin(),va.end(),1)>count(vb.begin(),vb.end(),1);
	if(a.second.score!=b.second.score) return a.second.score>b.second.score; //warn 优化 
	for(int i=2;i<=100;i++)
	{
		if(count(va.begin(),va.end(),i)!=count(vb.begin(),vb.end(),i)) 
			return count(va.begin(),va.end(),i)>count(vb.begin(),vb.end(),i);
	}
}

void solve()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			m[s].v.push_back(i);
			if(i<=10) m[s].score+=a[i];
		}
	}
//	cout<<endl;
	for(auto u:m) v.push_back({u.first,u.second});
	sort(v.begin(),v.end(),cmp1);
//	for(auto u:v)
//	{
//		cout<<u.first<<" "<<u.second.score<<endl;
//		auto vtemp=u.second.v;
//		for(int i=0;i<vtemp.size();i++) cout<<vtemp[i]<<" ";
//		cout<<endl;
//	}
	cout<<v[0].first<<endl;
	//2
//	cout<<endl;
	sort(v.begin(),v.end(),cmp2);
//	for(auto u:v)
//	{
//		cout<<u.first<<" "<<u.second.score<<endl;
//		auto vtemp=u.second.v;
//		for(int i=0;i<vtemp.size();i++) cout<<vtemp[i]<<" ";
//		cout<<endl;
//	}
	cout<<v[0].first<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1; 
	while(t--) solve();
	return 0;
}
