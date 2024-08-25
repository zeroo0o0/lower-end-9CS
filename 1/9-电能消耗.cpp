#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int l1=1000,rn=0;

void solve()
{
	int n,p1,p2,p3,t1,t2; cin>>n>>p1>>p2>>p3>>t1>>t2;
	int work[1445]={0};
	while(n--)
	{
		int l,r; cin>>l>>r;
		l1=min(l1,l);
		rn=max(rn,r);
		for(int i=l;i<=r;i++) work[i]=1;
	} 
	int ans=0,cnt=0;
	for(int i=l1;i<=rn-1;i++) //warn 题目不严谨 要少一个p1 
	{
		if(work[i]) {
			ans+=p1;
			cnt=0;
		}
		else 
		{
			cnt++;
			if(cnt>=t1&&cnt-t1<t2) 
			{
				ans+=p2;
//				cout<<i<<endl; //warn 记得删注释 
			}
			else if(cnt-t1>=t2)
			{
				ans+=p3;
//				cout<<3<<":"<<i<<endl;
			}
			else ans+=p1;
		}
	}
	cout<<ans;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
