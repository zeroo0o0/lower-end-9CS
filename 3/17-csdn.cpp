#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int Cfind(string s) {//统计问号个数 
	int su=0;
	for(int i=0; i<s.length(); i++) {
		if(s[i]=='?')su++;
	}
	return su;
}
int main() {
	string s;
	while(cin>>s) {
		string ss;
		cin>>ss;
		int sum=Cfind(s);//sum为问号数量 
		int num=0;
		for(int i=0; i<s.length(); i++) {
			if(s[i]=='?') {//遇到问号 
				sum--;//更新后面问号数量 
				num+=('9'-ss[i])*pow(10,sum);//假设X这位是7 ，W这位可以取 8和9，后面的问号可以取0到9 
			}
			if(s[i]!='?'&&s[i]>ss[i]) {//遇到数字，高位大，后面的所有问号都可以取0到9 
				num+=pow(10,sum);
				break;
			}
			if(s[i]!='?'&&s[i]==ss[i])continue;//遇到数字，高位相同，要继续比较低位 
			if(s[i]!='?'&&s[i]<ss[i])break;//遇到数字，高位小，低位就不用比了 
		}
		cout<<num<<endl;
	}
}

