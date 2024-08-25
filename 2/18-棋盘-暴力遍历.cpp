#include<bits/stdc++.h>
using namespace std;
/*
思路
1.用vector记录输入，注意字符转数字。
2.遍历所有的size，找出对应的所有棋盘的起始点。
3.check对应的棋盘是否满足要求即可
注意：如果当前遍历的size没有更新，那么后面的size就不用跑了
*/
const int maxn=2000+5;
char m[maxn][maxn];
int ans,cnt;

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>m[i][j];
	for(int size=1;size<=n;size++)
	{
		int temp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int x,y;
				bool flag=0;
				for(x=0;x<size;x++) //移动x步 
				{
					for(y=0;y<size;y++)
					{
						int nx=i+x, ny=j+y;
						if((x+y)%2==0) //warn: x+y not nx+ny 
						{
							if(m[nx][ny]=='1') continue; //warn 已经存为了0 1 
							else flag=1;
							break;
						}
						else {
							if(m[nx][ny]=='0') continue;
							else flag=1;
							break;
						}
					}
					if(flag) break;
				}
				if(x==size&&y==size) //正常结束
				{
					ans=size;
					temp++;
				} 
			}
		if(ans!=size) break;
		else cnt=temp;
	}
	cout<<ans<<" "<<cnt<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
} 
