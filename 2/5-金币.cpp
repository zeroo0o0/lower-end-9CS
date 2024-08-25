#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n;
	while(cin>>n)
	{
		int x=1;
		for(;x<n;x++)
		{
			int x1=x+1;
			if(x*(x+1)/2<=n&&x1*(x1+1)/2>n) break;
		}//平方和相加 公式：x*(x+1)*(2*x+1)/6
		int ans=x*(x+1)*(2*x+1)/6+(n-x*(x+1)/2)*(x+1);  //warn： n-x*(x+1)/2 
		cout<<n<<" "<<ans<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
