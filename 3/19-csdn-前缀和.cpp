#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string s;
	vector<int> a,b;
	cin>>s;
	/**********前缀和init初始化**************/
	if(s[0]=='a') {
		a.push_back(1);
		b.push_back(0);
	}else{
		a.push_back(0);
		b.push_back(1);
	} 
	for(int i=1;i<s.length();i++){
		if(s[i]=='a'){
			a.push_back(a[i-1]+1);
			b.push_back(b[i-1]);
		}else{// == 'b'
			a.push_back(a[i-1]);
			b.push_back(b[i-1]+1);
		}
	}
	int max=-1;//记录结果，最大值 
	int a_first,b_mid,a_final;//其实就是三个部分相加，
	//这个题用暴力也可以做，但是拿不到满分，所以我们用前缀和来降低复杂度 
	/************下面遍历两个节点，可以截出三个部分作为上面的三个部分***********************/
	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			a_first=a[i-1];//第一部分所有的a 
			b_mid=b[j]-b[i-1];//第二部分所有的b 
			a_final=a[s.length()-1]-a[j];//第三部分所有的a 
			if(a_first+b_mid+a_final>max){
				max=a_first+b_mid+a_final;
			} 
		}
	} 
	cout<<max<<endl;
	return 0;
} 

