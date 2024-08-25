#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<char,int>m;
vector<string>ans;
string s; 

void check(string t)
{
	int n=t.size();
	for(int i=1;i+t[0]-'0'<10;i++)
		if(m[t[0]+i]>=n)
		{
			string t0=to_string(t[0]-'0'+i);
			string temp;
			for(int i=0;i<n;i++) temp+=t0;
			ans.push_back(temp); 
		}
}

void solve()
{
	cin>>s;
	sort(s.begin(),s.end()); 
//	cout<<s<<endl;
	for(int i=0;i<s.size();i++)
		m[s[i]]++;
	string t; 
	while(cin>>t)
	{
		ans.clear();
		if(t.size()!=5) check(t);
		else
		{
			for(int k=1;k+t[4]-'0'<10;k++) //最后一位最多能加几 
			{
				int cnt=0;
				string temp="";
				for(int i=0;i<t.size();i++) //warn：*** t.size()
					if(m[t[i]+k])
					{
						cnt++;
						temp+=to_string(t[i]-'0'+k); //warn:t[i]-'0'+k not t[0]
						if(cnt==5) ans.push_back(temp);
					} 
			}
		}
		if(ans.size()==0) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<" ";
			for(auto u:ans) cout<<u<<" ";
			cout<<endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
