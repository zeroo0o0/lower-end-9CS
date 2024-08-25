/*
1.模拟题嘛，地图先记录下来，我们输入的是字符，我们直接存int就可以了，这样跳的时候会方便一点
注意：递归出口要找好
注意：反向 传送 击飞 三个判断都要有
注意：模拟题一定要仔细！！！
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,a,b,c, A,B; //A，B当前位置 
int mp[205];

void work(int cnt, int step) //方向  下一次 步数 
{
	if(A==n-1||B==n-1) //终止条件
	{
		if(A==n-1) cout<<"Lele"<<endl;
		else cout<<"Yueyue"<<endl;
		return;
	} 
	if(cnt==0) //L 
	{
		A+=step;
		if(A>=n) A=n-1-A%(n-1); //往回走A%(n-1) 步 
		while(mp[A]!=0) A=mp[A];
		if(B==A) B=0;

	}
	else  //Y
	{
		B+=step;
		if(B>=n) B=n-1-B%(n-1); //往回走B%(n-1) 步 
		while(mp[B]!=0) B=mp[B];
		if(B==A) A=0;
	}
	work((cnt+1)%2,(a*step+b)%6+1);
}

void solve()
{
	while(cin>>n>>a>>b>>c) //warn: >> not >
	{
		A=B=0;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++)
		{
			char c; cin>>c;
			if(c=='G')
			{
				int num; cin>>num; 
				mp[i]=num;
			}
		}
		work(0,(a*c+b)%6+1); //warn: +b
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
