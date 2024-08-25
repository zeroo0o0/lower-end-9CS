#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair<char,char>
map<pii,int>m;
int a1,a2,a3,b1,b2,b3;
map<char,int>cnta,cntb;
#define pii2 pair<char,int> 
vector<pii2>va,vb;

bool cmp(pii2 a,pii2 b)
{
	if(a.second!=b.second) return a.second>b.second;
	else return a.first<b.first;
}

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		char a,b; cin>>a>>b;
		if(m[{a,b}]==1) a1++,b3++,cnta[a]++; //warn [{a,b}]  有[]//warn: a not 'a'
		if(m[{a,b}]==0) a2++,b2++;
		if(m[{a,b}]==-1) a3++,b1++,cntb[b]++;
	}
	cout<<a1<<" "<<a2<<" "<<a3<<endl;
	cout<<b1<<" "<<b2<<" "<<b3<<endl;
	for(auto u:cnta) va.push_back({u.first,u.second});
	sort(va.begin(),va.end(),cmp);
	for(auto u:cntb) vb.push_back({u.first,u.second}); //warn cntb可能是空的就不能这样 
	sort(vb.begin(),vb.end(),cmp);						//***若为空 则for(auto u:cntb) 会运行时错误 
	cout<<va[0].first<<" "<<vb[0].first<<endl; 
}

int main()
{
	m[{'C','J'}]=1, m[{'J','B'}]=1, m[{'B','C'}]=1;
	m[{'J','C'}]=-1, m[{'B','J'}]=-1, m[{'C','B'}]=-1;
	string s="CBJ";
	for(int i=0;i<3;i++) cnta[s[i]]=0,cntb[s[i]]=0;
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
