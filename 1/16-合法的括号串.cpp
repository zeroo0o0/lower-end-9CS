#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<char,char>m;

void solve()
{
	string s; cin>>s;
	stack<char>stk;
	for(int i=0;i<s.size();i++)
	{
		char c=s[i];
		if(stk.empty()&&(c=='>'||c==')'||c=='}'||c==']')){
			cout<<"No"<<endl; return; //warn： return不能接到别的句子,  后面 
		}
		if(c=='<'||c=='('||c=='['||c=='{') stk.push(c);
		if(c=='>'||c==')'||c=='}'||c==']')
		{
			char x=stk.top(); 
			stk.pop(); //pop不返回栈顶元素 
			if(x!=m[c])
			{
				cout<<"No"<<endl; return;
			}
		}
	}
	if(stk.empty()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	m['>']='<', m[')']='(', m['}']='{', m[']']='[';
	int t; cin>>t; 
	while(t--) solve();
	return 0;
}
