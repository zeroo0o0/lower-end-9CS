#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,string>m1,m2; 

void solve()
{
	string s;
	while(getline(cin,s)&&s!="@END@")
	{
//		int pos1=s.find('['); //下标肯定是0 
		int pos=s.find(']');
		string s1=s.substr(0,pos+1); //warn ;
		string s2=s.substr(pos+2);
		m1[s1]=s2; //咒语字典 
		m2[s2]=s1; //功能 
	}
	int n; cin>>n;
	cin.get(); //取走cin与getline间的换行符 
	for(int i=0;i<n;i++)
	{
		getline(cin,s); //复用
//		cout<<i<<" "<<s<<endl;
		if(m1[s]==""&&m2[s]=="") cout<<"what?"<<endl;
		if(m1[s]!="") cout<<m1[s]<<endl;
		if(m2[s]!="")
		{
			string ans=m2[s];
			int pos=ans.find(']'); 
			ans=ans.substr(1,pos-1); //warn：不要[] 
			cout<<ans<<endl; 
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
