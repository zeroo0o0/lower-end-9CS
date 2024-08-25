#include<bits/stdc++.h>
using namespace std;
char a[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e'};

void solve()
{
	int b; string s; cin>>b>>s;  //Ó¦¸Ã¶Á string 
	int sum=0;
	for(int i=0;i<s.size();i++) 
	{
		if(s[i]>='0'&&s[i]<='9') sum+=s[i]-'0';
		else sum+=s[i]-'a'+10; //warn sum+= not s[i]
	}
//	cout<<sum<<endl;
	for(int i=0;i<b;i++)
		if((sum+i)%(b-1)==0) 
		{
			cout<<a[i]<<endl;
			return;
		}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
	return 0; 
}
