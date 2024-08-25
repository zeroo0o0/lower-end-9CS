#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	string a;
	int b,r=0;
	vector<int> res;
	cin>>a>>b;
	if(a.length()==1){
		cout<<(a[0]-'0')/b<<" "<<(a[0]-'0')%b<<endl;
		return 0;
	}
	for(int i=0;i<a.length();i++){
		r=r*10+a[i]-'0';
		res.push_back(r/b);
		r%=b;
	}
	for(int i=0;i<res.size();i++){
		if(i==0&&res[i]==0) continue;
		cout<<res[i];
	}
	cout<<" "<<r<<endl;
	return 0;
} 

