/*
思路
1.这个题开始看会有点蒙，其实很简单的，就是看成三个部分，前面是a，中间是b，后面是a。暴力就可以做，两层循环然后遍历三个部分，然后数里面的a和b就可以了
2.但是暴力解法是无法通过全部样例的
3.所以我们有了前缀和，这个就和前n项和是一样的，这样一说，大家肯定都懂了，大家高考数学做的题目中，已知前n项和表达式，求an的表达式这些…
4.这样，我们计算某个区间的a和b就可以简化了，比如是第一个部分的a不用一个个去数了，可以直接调用
5.第二个部分的b可以，用两个点的b相减得到中间区间的b
6.遍历两个节点，得到所有情况的三个部分，然后我们计算三个部分的值相加，求出最大值即可
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
const int maxn=5005; //warn：最长5000 
vector<int>a(maxn),b(maxn);
int mx,a1,b0,a2;

void solve()
{
	string s; cin>>s;
	if(s[0]=='a') a[0]=1,b[0]=0; //warn b[0]=0
	else b[0]=1, a[0]=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='a') a[i]=a[i-1]+1, b[i]=b[i-1];
		else a[i]=a[i-1], b[i]=b[i-1]+1;
	}
//	cout<<b[2]<<endl; cout<<b[5]<<endl; 
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size();j++) //暴力枚举 两个分割点 
		{//warn：若i=0，a[i-1]会越界 //不行，不从0开始得不到最优解 
			if(i==0) a1=a[0],b0=b[j]-0; //warn 初始化时b！=0 
			else a1=a[i],b0=b[j]-b[i]; //warn -b[i-1]  //0~i:a  i+1~j:b j+1~end:a  //warn b[j] not b[j-i]
			a2=a[s.size()-1]-a[j];
			int sum=a1+b0+a2;
//			cout<<i<<" "<<j<<":";
//			cout<<a1<<" "<<b0<<" "<<a2<<endl;
			if(sum>mx) mx=sum;
		}
	cout<<mx<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
