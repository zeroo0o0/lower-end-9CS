#include<iostream>
using namespace std;

int a[30];//ai
int b[30];//bi,下标对应次数
int aE[30];//ai的展开式,下标对应次数
int main() {
	int n;
	while(cin>>n&&n>0) {

		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=n-1; i>=0; i--) {
			cin>>b[i];
		}
		b[n]=1;//x^n的系数为1
		aE[0]=a[1];//假设只有一项(x+a1),则x的0次方系数为a1
		aE[1]=1;//假设只有一项(x+a1),则x的1次方系数为1
		for(int i=2; i<=n; i++) {//i从2开始到n,就是从(x+a2)开始乘上去,一直乘到(x+an),每次更新展开式每一项系数的变化
			aE[i]=1;//如果乘到ai,那么x^i为最高项次数为1
			for(int j=i-1; j>0; j--)
				aE[j]=aE[j]*a[i]+aE[j-1];//乘上(x+ai)后，x^j的原系数*ai加上x^j-1的系数(和x乘后次数变为j，系数不变)为x^j的新系数
			aE[0]*=a[i];//常数项*ai
		}

		int flag = 0;
		for(int i=0; i<n; i++) {
			if(b[i]==aE[i])flag++;//判断bi是否和ai展开式一一对应
		}

		if(flag==n)cout<<'Y'<<endl;
		else cout<<'N'<<endl;
	}
}

