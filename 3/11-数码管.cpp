/*法一 
1.用数组记录下数码管的亮灭，我们将两个数字数组相减，如果都同号说明只需加或者减
2.这个思路是不是挺妙，哈哈
*/
/*
法二：转换矩阵 
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int m[15][15]={
{0,1,0,0,0,0,0,1,1,0},//0
{1,0,0,1,1,0,0,1,1,1},//1
{0,0,0,0,0,0,0,0,1,0},//2
{0,1,0,0,0,0,0,1,1,1},//3
{0,1,0,0,0,0,0,0,1,1},//4
{0,0,0,0,0,0,1,0,1,1},//5
{0,0,0,0,0,1,0,0,1,0},//6 //注意六的写法 
{1,1,0,1,0,0,0,0,1,1},//7
{1,1,1,1,1,1,1,1,0,1},//8
{0,1,0,1,1,1,0,1,1,0} //9
};

void solve()
{
	while(1){
		int last=0,now=0,flag=1;
		for(int i=0;i<10;i++)
		{
			cin>>now;
			if(i==0&&now==-1) return; //warn：i==0 才是第一个 
			if(i==0) last=now; //可以先vector存v[i-1],v[i] 
//			cout<<last<<" "<<now<<endl;
			if(m[last][now]||last==now) 
			{
				last=now; //更新上一个 
				continue; //last==now:第一个 
			}
			else 
			{
				flag=0;
//				break;  warn: 输入未完成，不能break 
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

signed main()
{
	
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
