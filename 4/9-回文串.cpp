#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 

int check(string s)
{
	string t=s;
	reverse(s.begin(),s.end());
	if(t==s) return true;
	else return false;;
}

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		string s; cin>>s; //warn
		for(int i=0;i<=s.size();i++) //最长在后面 反着接一个s
		{
			string temp=s.substr(0,i);
			//warn temp要reverse
			reverse(temp.begin(),temp.end()); 
			string u=s+temp;
			if(check(u))
			{
				cout<<i<<endl;
				break;
			}
		} 
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
