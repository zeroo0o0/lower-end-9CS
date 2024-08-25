#include<bits/stdc++.h>  //warn 这不就是一个八进制吗 
using namespace std;	//这个题告诉我们要仔细从题目中寻找提示 
#define endl '\n'
#define int long long 
/*
1.里程表里面3和8无法显示，也就是说，可以一个位置只会有0 1 2 4 5 6 7 9八个数字。这不就是一个八进制数了吗？
2.那我们先把这个数转换为正常的八进制数(比如 19其实是17)
3.然后我们把这个八进制数转换为10进制数就得到正确的里程数了！
*/

void solve()
{
	int t; cin>>t;
	while(t--)
	{
		int x; cin>>x;
		int ans=0;
		string s=to_string(x);
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size();i++)	
		{
			if(s[i]>='3'&&s[i]<'8') s[i]--; //warn -- not ++
			if(s[i]>'8') s[i]-=2;
			ans+=(s[i]-'0')*pow(8,i);
		}
		cout<<ans<<endl; 
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
