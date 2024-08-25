#include<bits/stdc++.h> //***换文件了你不知道吗 
using namespace std;
#define endl '\n'
int a[10];

int check()
{
	if(a[0]==a[1]&&a[1]==a[2]&&a[0]) return a[0];
	if(a[3]==a[4]&&a[4]==a[5]&&a[3]) return a[3];
	if(a[6]==a[7]&&a[7]==a[8]&&a[6]) return a[6]; //warn： 可能有三个零连在一起应该跳过 
	if(a[0]==a[3]&&a[3]==a[6]&&a[0]) return a[0];
	if(a[1]==a[4]&&a[4]==a[7]&&a[1]) return a[1];
	if(a[2]==a[5]&&a[5]==a[8]&&a[2]) return a[2];
	if(a[0]==a[4]&&a[4]==a[8]&&a[0]) return a[0];
	if(a[2]==a[4]&&a[4]==a[6]&&a[2]) return a[2];
}

void solve()
{
	int n; string s; cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			char c; cin>>c;
			a[j]=c-'0'; //warn：int会直接222当成一个数 
		}
//		cout<<i<<":";
		if(check()==1) cout<<s[i]<<endl;
		if(check()==2)
		{
			if(s[i]=='A') cout<<"B"<<endl;
			else cout<<"A"<<endl; 
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
