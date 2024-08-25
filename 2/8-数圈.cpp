#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
1.这种题就是找好规律然后模拟就可以了 
注意：方向控制写个数组，这样思路清晰又方便控制
*/
int dx[]={0,1,0,-1};//ESWN //行
int dy[]={1,0,-1,0};	   //列 

void solve()
{
	int n; cin>>n;
	int mp[n][n];
	int dir=0; //记录方向
	int buchang=1; //下次需要往dir走几步
	int cnt=0;//***局部变量 一定要初始化*** //走两次相同步长 ，则步长+1
	int i=1;
	int x,y; x=y=(n-1)/2; //算出初始位置 
	mp[x][y]=i;
	while(i<n*n) //warn: < not <=
	{
		for(int j=1;j<=buchang;j++) //warn i被用了 只能j 
		{
			mp[x+j*dx[dir]][y+j*dy[dir]]=++i; //模拟手动放数  //warn: j*dx[dir] not buchang
			if(i==n*n) break; //防止 越界 
		}
		//warn 更新x,y
		x+=buchang*dx[dir];
		y+=buchang*dy[dir];
		cnt++;
		if(cnt==2)
		{
			buchang++,cnt=0;
		}
		dir++;
		if(dir==4) dir=0; 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;		
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
