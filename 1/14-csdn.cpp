#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string days[7]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int get_day(string str){
	for(int i=0;i<7;i++){
		if(days[i]==str)
			return i+1;
	}
	return -1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		int d_begin,d_end;
		int l,r;
		int sum=0,ans;
		cin>>a>>b>>l>>r;
		d_begin=get_day(a);
		d_end=get_day(b);
		int temp=d_end-d_begin+1;
		if(d_begin>d_end) temp+=7; 
		for(int j=l;j<=r;j++){  
			if(j%7==temp%7) {  //warn jÈ¡ÓàÓÚ7
				sum+=1;
				ans=j;
			}
			
		}
		if(sum==0) cout<<"impossible"<<endl;
		if(sum==1) cout<<ans<<endl;
		if(sum>1)  cout<<"many"<<endl;
	}
	return 0;
} 

