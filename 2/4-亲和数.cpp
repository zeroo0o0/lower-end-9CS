#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a,b; 

int cnt(int x)
{
	int sum=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0) //warn % not &
		{
			if(i!=1||i*i!=x) sum+=i+(x/i);
			else sum+=i;
//			cout<<i<<" "<<x/i<<endl;
		}
	}
	return sum; //warn return
}

void solve()
{
	while(cin>>a>>b)
	{
		if(cnt(a)==cnt(b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
