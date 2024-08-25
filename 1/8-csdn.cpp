#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
	cout<<l<<endl;
	if(l>18)return printf("No\n"),0;
	string qaq[18];
	qaq[0]=s;
	for(int i=1;i<l;i++){
		qaq[i]="";
		for(int j=i;j<i+l;j++)
			qaq[i]+=s[j%l];
	}
	long long num=0;
	for(int i=0;i<l;i++)
		num=num*10+s[i]-'0'; //转化为数字 
	bool flag; 
	for(int i=2;i<=l;i++){
		long long b=num*i;
		flag=false;
		if(b>=pow(10,l))break;
		for(int j=0;j<l;j++){
			long long c=0;
			for(int k=0;k<l;k++)
				c=c*10+qaq[j][k]-'0'; //转化为数字 
			if(b==c){
				flag=true;
				break;
			}
		}
		if(!flag)break;
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;
}
