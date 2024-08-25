#include<bits/stdc++.h>
using namespace std;

void solve()
{
	double x1,y1,x2,y2,x3,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0) return;
		double a,b,c,p;
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		p=(a+b+c)/2;
		double ans=sqrt(p*(p-a)*(p-b)*(p-c));
		cout<<fixed<<setprecision(6)<<ans<<endl;
	} 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
