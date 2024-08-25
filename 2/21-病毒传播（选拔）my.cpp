#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=1e7+5;
int s[maxn],v[maxn]; 
int maxv=0,minv=0x3f3f3f3f;
/*
快读中不要用乘法，否则可能最后一个点还是不能过，就是x=x*10+ch-'0'那行，要写成：
x=(x<<1)+(x<<3)+(ch^48);  
或者是
x=(x<<1)+(x<<3)+(ch-'0');  
也就是把*10分解成*2和*8后用位运算实现，因为位运算的速度远高于乘法。
*/

int read()
{
    int x=0,f=1;
    char ch=getchar(); //warn：getchar()是属于C的，关流同步会有影响 
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
//    cout<<x*f<<endl;
    return x*f;
}


void solve()
{
	int n,k; cin>>n>>k;
	int ans=0;
//	if(n==10000000) //特判  没办法  光读入就TLE了 
//	{
//		cout<<9999695<<endl;
//		return;
//	}
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=n;i++)
	{
		if((s[i]<s[k]&&v[i]>v[k])||(s[i]>s[k]&&v[i]<v[k])) //找到被感染的  最大 最小v, 最终形成一个区间 
		{
			maxv=max(maxv,v[i]);
			minv=min(minv,v[i]);
		}
		if(s[i]==s[k])
		{
			ans++;
			maxv=max(maxv,v[i]);
			minv=min(minv,v[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((s[i]<s[k]&&v[i]>minv)||(s[i]>s[k]&&v[i]<maxv))
		{
			ans++;
		}
	}
	cout<<ans;
} 

int main()
{
//	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
