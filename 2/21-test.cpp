#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int s[maxn],v[maxn]; 

int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void solve()
{
	int n,k; cin>>n>>k;
	cout<<n<<" "<<k<<endl;

} 
 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
