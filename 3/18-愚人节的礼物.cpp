#include<bits/stdc++.h>
using namespace std;
#define pii pair<char,char>
map<pii,int>m;
/*
思路
1.这题很简单，找B左边的左括号就可以了
2.左边出现右括号要--，因为这个盒子打开是空的
3.总而言之，就是左边的左括号减去左边的右括号就可以了
*/
/*
法二： 借助计算机删除空盒子 
*/

void solve()
{
	string s;
	string s0="()";
	while(cin>>s)
	{
//		cout<<s<<endl;  //warn：注释测试代码 
		while(s.find(s0)!=-1) s.erase(s.find(s0),2);
		int ans=s.find('B');
		cout<<ans<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	m[{'(',')'}]=1;
	solve();
	return 0;
}
