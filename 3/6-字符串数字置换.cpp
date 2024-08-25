#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string str[]={"(Zero)","(One)","(Two)","(Three)","(Four)","(Five)","(Six)","(Seven)","(Eight)","(Nine)"};
map<char,string>m;
map<char,int>cnt;

void solve()
{
	string s; 
	getline(cin,s); //warn审题：输入一行字符串，其中可包含字母、数字、空格或其他符号（英文）
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			cnt[s[i]]++;
			s.replace(i,1,m[s[i]]);
//			cout<<s.size()<<endl;  //会随着变化 
		}
	}
	cout<<s<<endl;
	for(int i=0;i<10;i++) cout<<cnt[i+'0']<<" "; //warn: i+'0'
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<10;i++) m[i+'0']=str[i];
//	for(auto u:m) cout<<u.first<<" "<<u.second<<endl;
	solve();
	return 0;
}
