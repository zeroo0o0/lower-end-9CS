#include<iostream>
using namespace std;
int a[65],b[65],cd=0,sum[10],sum1[10];
int main(){
	string s;
	cin>>s;
	cout<<s<<endl<<s.size()<<endl;
	cd=s.size();
	for(int i=0;i<cd;i++){
		a[i]=b[i]=s[i]-'0';
		sum[a[i]]++;
	}
	int t=cd-1;
	while(t--){
		for(int i=cd-1;i>=0;i--){
			b[i]+=a[i];
			if(i==0&&b[i]>10){
				cout<<"No";
				return 0;
			}
			if(b[i]>=10){
				b[i-1]+=1;
				b[i]-=10;
			}
		}
		for(int i=0;i<cd;i++){
			//cout<<b[i]<<" ";
			sum1[b[i]]++;
			if(sum1[b[i]]>sum[b[i]]){
				cout<<"No";
				return 0;
			}
		} 
		//cout<<endl;
		for(int i=0;i<10;i++){
			sum1[i]=0;
		} 
	}
	cout<<"Yes";
}
