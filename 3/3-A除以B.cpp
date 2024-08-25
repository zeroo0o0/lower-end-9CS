#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
思路
1.小学的除法算法
2.提交后有个问题，第三个样例没过，之后发现是一位的数字有问题，所以做了一个特判，就全过了
*/

void solve()
{
	string a; int b; cin>>a>>b;
	vector<int> ans;
	int r=0; //余数 
	for(int i=0;i<a.size();i++)
	{
		r=r*10+a[i]-'0';
		ans.push_back(r/b);
		r%=b;
	}
	int i=0;
	while(ans[i]==0&&i<ans.size()) i++;
	if(i==ans.size()) cout<<0;
	else while(i<ans.size()) cout<<ans[i++];
	cout<<" "<<r<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
