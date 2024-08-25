#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		int a=0,b=0;
		vector<string>v1,v2;
		string s1=" good", s2=" no good";
		for(int i=1;i<=n;i++)
		{
			cin.get(); //***warn cin和getline之间 
			string s;
			getline(cin,s);
			
			if(i%2!=0)
			{
//				cout<<1<<" "<<s<<endl;
				if(s.find(s2)!=-1) v1.push_back("X");
				else v1.push_back("O"),a++;
			}
			else 
			{
//				cout<<2<<" "<<s<<endl;
				if(s.find(s2)!=-1) v2.push_back("X");
				else v2.push_back("O"),b++;				
			}
		}
		for(int i=1;i<=ceil((double)n/2);i++) //warn: (double)n/2 若不强转则尾数已经约去 
			cout<<i<<" ";
		cout<<"Score"<<endl;
		for(int i=0;i<v1.size();i++) cout<<v1[i]<<" "; cout<<a<<endl;
		for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";
		if(n%2!=0) cout<<"-"<<" "; cout<<b<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
