#include "stdio.h"
char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int year[2]={365,366};
int month[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int type(int m)
{
	//判断第m年是否是闰年,是则返回1,否则返回0
	if (m % 4 != 0 || (m % 100 == 0 && m % 400 != 0))
		return 0;
	else return 1;
}
 
int main(int argc, char const *argv[])
{
	int days,dayofweek;//days表示输入的天数,dayofweek表示星期几
	int i = 0,j = 0;
	while(scanf("%d",&days) && days != -1)
	{
		dayofweek = days % 7;
		for(i = 2000;days >= year[type(i)]; i++)
			days -= year[type(i)];
		for(j = 0;days >= month[type(i)][j]; j++)
			days -= month[type(i)][j];
		printf("%d-%02d-%02d %s\n",i,j+1,days+1,week[dayofweek] );
	}
	return 0;
}	
