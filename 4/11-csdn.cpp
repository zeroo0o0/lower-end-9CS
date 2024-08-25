#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int day[n];//ai
	for(int i=0; i<n; i++) {
		cin>>day[i];
	}
	int dp[n][3];//0编程 1运动 2休息,dp[i][j]表示第i+1天(dp[0]表示第1天)为j状态,此时休息的最少天数
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++)dp[i][j]=INT_MAX;

	if(day[0]==1)dp[0][0]=0;//若第1天编程，休息0天
	if(day[0]==2)dp[0][1]=0;//若第1天运动，休息0天
	if(day[0]==3) {//若第1天编程或运动
		dp[0][1]=0;//选编程，休息0天
		dp[0][0]=0;//选运动，休息0天
	}
	dp[0][2]=1;//若第1天休息，休息1天

	for(int i=1; i<n; i++) {
		if(day[i]==1)dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//若编程，则上一天只能运动或休息
		if(day[i]==2)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//若运动，则上一天只能编程或休息
		if(day[i]==3) {//若编程或运动
			dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//选编程
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//选运动
		}
		dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;//若休息，则上一天三者均可
	}
	int result=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));//结果为最后一天三种状态的最小值
	cout<<result;
}

