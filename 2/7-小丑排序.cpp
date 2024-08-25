#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
1.这个题看着复杂，其实很简单啊，用两个vector记录下奇偶输入就可以了
2.奇数次直接输出，偶数次倒序输出
*/

void solve()
{
	int n; int cnt=1;
	while(cin>>n&&n)
	{
		vector<string>va,vb;
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			if(i%2!=0) va.push_back(s); //warn 边输入 边处理数据 
			else vb.push_back(s);
		}
		cout<<"set-"<<cnt<<endl;
		for(int i=0;i<va.size();i++) cout<<va[i]<<endl;  //NB 偶数位反着输出 
		for(int i=vb.size()-1;i>=0;i--) cout<<vb[i]<<endl;
		cnt++;		
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
