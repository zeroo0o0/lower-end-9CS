/*
#include <iostream>
using namespace std;
int main(){
	int n, m, sum = 0, tmp, maxm = 0, minm = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		sum += tmp;
		if(sum > maxm) maxm = sum;
		if(sum < minm) minm = sum;
	}
	int result = m - maxm + 1 + minm; 
	if(result > 0) cout << result;
	else cout << 0;
	return 0;
}
*/
#include <iostream>
using namespace std;
int main() {
	int n,w;
	int sum=0,max=0,min=0,re;//假设初始乘客为0
	int a;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>a;sum+=a;
		if(sum>max)max=sum;//求整个过程中出现过的最大乘客数
		if(sum<min)min=sum;//求整个过程中出现过的最小乘客数
	}
    //边界为min到max，即初始乘客数i需满足让区间[min+i,max+i]在[0,w]之中
	if(min<0)re=w-max+min+1;//min<0，i只能从0开始，所以要减去|min|    //解两个不等式 
	else re=w-max+1;//i最小为0，最大时max+i=w，所以有w-max+1种情况
	if(re>=0)cout<<re;
	else cout<<0;
}

