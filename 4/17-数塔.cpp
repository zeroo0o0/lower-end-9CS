/*
【思路】 
一道基本的动态规划题。我用的是递归求解，没有建二维数组（所以保存路径有亿点点麻烦）
有点类似于满二叉树的储存方法，用一个一维数组储存整个数塔，顶点编号为0，层数为1；
这样子，每个点的左右子节点就是它（自身编号+层数）或者（自身编号+层数+1）
记录路径：path数组在递归时储存【最大值路径】中每层所选择的子结点，一个接一个地输出来就行~
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int a[100000],path[100000], size, n;

int dfs(int now, int floor) //现在  层数   左右子节点就是它（自身编号+层数）或者（自身编号+层数+1）
{
	if(floor==n) return a[now];
	int left=a[now]+dfs(now+floor,floor+1);
	int right=a[now]+dfs(now+floor+1,floor+1);
	if(left>right) path[now]=now+floor;
	else path[now]=now+floor+1;
	return max(left,right);
}


void solve()
{
	cin>>n;
	size=n*(n+1)/2;
	for(int i=0;i<size;i++) cin>>a[i]; //warn**<size
	int ans=dfs(0,1);
	cout<<ans<<endl;
	int cnt=0, now=0;
	while(cnt<n)
	{
		cout<<a[now]<<" ";
		now=path[now];
		cnt++;
	}
}


signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
