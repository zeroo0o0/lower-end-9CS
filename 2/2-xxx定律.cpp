#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve(int x)
{
	int cnt=0;
	while(x!=1)
	{
		if(x%2==0) x/=2;
		else x=(3*x+1)/2;
		cnt++; //warn
	}
	cout<<cnt<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int x;
	while(cin>>x&&x) solve(x);
	return 0;
}
