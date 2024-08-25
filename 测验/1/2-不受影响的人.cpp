/*思路： 
优先对时间排序，时间相同的情况下分数高的优先
当前点的时间<=后续所有的点的时间，所以后续所有点凡是成绩小于当前点的，一律是被激励的。
也就是你需要的就是记录当前点的成绩作为一个阈值，并且遇到更大的成绩就用更大的成绩替换掉这个阈值，对于每个点，
你只需要比较这个点的成绩是否小于阈值，小于就是被激励，等于且时间更靠后也是被激励，若时间相等则不被激励 
否则就是不被激励，保存编号并且把当前阈值更新为新的阈值
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
struct node{
	int id,t,score;
};
const int maxn=1000005;
node a[maxn];

bool mycmp(node x,node y)
{
	if(x.t!=y.t) return x.t<y.t; //warn: cmp函数里不要忘记return
	else return x.score>y.score;
}

set<int>ans;
void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) //warn: 0~n
	{
		cin>>a[i].t>>a[i].score;
		a[i].id=i+1;
	}
	sort(a,a+n,mycmp);
	int mx=0,nowt=0; //当前最高分 
	for(int i=0;i<n;i++) //审题：（如甲乙的做题时间和题目得分都相同则甲乙都不能受到激励） 
		if(a[i].score>mx||(a[i].t==nowt&&a[i].score==mx))
		{ 		  // > not >=
			ans.insert(a[i].id);
//			cout<<a[i].id<<endl;
//			cout<<mx<<" "<<a[i].score<<endl; 注释掉！ 
			mx=a[i].score;
			nowt=a[i].t;
		}
	for(auto u:ans) cout<<u<<endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
