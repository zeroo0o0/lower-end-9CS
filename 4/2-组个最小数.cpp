#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
map<int,int,greater<int>>m;

void solve()
{
	int x;
	string s="";
	while(cin>>x) 
	{
		m[x]++;
//		cout<<x<<" ";
		s+="0";
	}
	cout<<endl;
	if(m[1]) s[0]='1',m[1]--;
	for(int i=s.size()-1;i>=0;i--) //warn: -- //***>=0 有些无1 
	{
		for(auto u:m)
		{
			if(u.second>0) 
			{
				s[i]=(u.first+'0'); //warn: +'0'
				m[u.first]--;
				break;
			}
//			if(!m.empty()) m.erase(m.find(u.first)); //不行，dev可能出奇怪的bug 
		}
	}
	cout<<s<<endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}

