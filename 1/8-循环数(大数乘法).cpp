#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],ans[100];
bool multiple(string num1,string num2)
{
//	cin>>num1>>num2;
//	cout<<num1<<" "<<num2<<endl;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(ans,0,sizeof(ans)); //warn   :  必须清空ans 
	for(int i=0,j=num1.size()-1;j>=0;i++,j--)
		a[i]=num1[j]-'0';
	for(int i=0,j=num2.size()-1;j>=0;i++,j--)
		b[i]=num2[j]-'0';
	for(int i=0;i<num1.size();i++)
		for(int j=0;j<num2.size();j++)
		{
			ans[i+j]+=a[i]*b[j]; //warn：* 
		}
	for(int i=0;i<num1.size()+num2.size();i++)
		if(ans[i]>=10)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	int i=100-1; //warn 两千就越界了 
	while(ans[i]==0&&i>0) i--; //warn：&&i>0  否则有一个为0时越界 
//	cout<<i+1<<endl;  //warn 0~i 共i+1位 
	if(i+1>num1.size()) return false;
	string s="";
	while(i>=0) s+=to_string(ans[i--]); //warn 转化为string 
	if(num1.size()>s.size())
		for(int i=0;i<num1.size()-s.size();i++) s="0"+s;; 
//	cout<<s<<endl;
	s=s+s;
//	cout<<s<<endl;
	if(s.find(num1)!=-1) return true; //find
	else return false;
}

void solve()
{
	string s;
	cin>>s;
//	cout<<s.size()<<endl;
	for(int i=1;i<=s.size();i++)
	{
		if(!multiple(s,to_string(i)))
		{
			cout<<"No"; return;
		}
	}
	cout<<"Yes";
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
