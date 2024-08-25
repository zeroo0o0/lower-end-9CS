#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
multimap<int,int>m;
double sum1;
double sum2;

double cnt(int x)
{
	if(x>=90) return 4.0;
	if(x>=85) return 3.7;
	if(x>=82) return 3.3;
	if(x>=78) return 3.0;
	if(x>=75) return 2.7;
	if(x>=72) return 2.3;
	if(x>=68) return 2.0;
	if(x>=64) return 1.5;
	if(x>=60) return 1.0;
	return 0.0;
}

void solve()
{
	int n; cin>>n;
	double a[n], b[n];
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; sum1+=a[i];
	}
	for(int i=0;i<n;i++) 
	{
		cin>>b[i]; sum2+=a[i]*cnt(b[i]);
	}
	double ans=sum2/sum1;
	cout<<fixed<<setprecision(2)<<ans<<endl;
	
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
