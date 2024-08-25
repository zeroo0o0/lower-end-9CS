/*
思路
1.感觉就和进制转换很像
2.先变成统一度量的总天数
3.再按照规则转换就可以了！
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string s0[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string tdays[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};		
map<string,int>hyues;

void solve()
{
	string s; int hyear; cin>>s>>hyear;
	int hday=stoi(s);
	string hyue=s.substr(s.find('.')+1); //取出"." 之后的 
	int hmonth=hyues[hyue];
	int sum=hyear*365+hmonth*20+hday; //第二月 =1*20+天数
	int tyear=sum/260; 
//	sum%=260; //可有可无，因为13，20也是260的因数 
	int tday=sum%13+1;
	string td_name=tdays[sum%20];
	cout<<tday<<" "<<td_name<<" "<<tyear<<endl; 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<19;i++) hyues[s0[i]]=i; //huyues[]
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
