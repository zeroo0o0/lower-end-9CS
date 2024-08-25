/*
类似加法的进位原理，判断何时需要进位，准确控制精确输出
思路：
首先百度一下2001年1月1日是星期六 ，（总之是要确定第一天是星期几才行，也有一些别的公式
不断地用n减去365或者366，直到它小于当年的天数，这时候可以确定年份了；
月份类似的道理，减去一个月，减去两个月，直到n小于当月，确定了月份；
剩下的n值自然就是天数（别忘了单个位数前面补上“0”）
星期的话很简单，直接用(6+n) % 7 就行 ~ 
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
				  {31,29,31,30,31,30,31,31,30,31,30,31}};
int year[]={365,366};
string week[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

bool check(int x)
{
	if(x%4!=0||(x%100==0&&x%400!=0)) return 0;
	return 1;
}

void solve()
{
	int days;
	while(cin>>days&&days!=-1)
	{
		int dayofweek=days%7; //星期几 
		int i=2000, j=0;
		for(;days>=year[check(i)];i++) //warn num>=
			days-=year[check(i)];
		for(j=0;days>=month[check(i)][j];j++)
			days-=month[check(i)][j];
		string ans_month=to_string(j+1);
		if(j+1<10) ans_month="0"+ans_month;
		string day=to_string(days+1); //warn  days+1  从1号开始 
		if(days+1<10) day="0"+day;
		cout<<i<<"-"<<ans_month<<"-"<<day<<" "<<week[dayofweek]<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
