/*
1. 观察一下可以发现, 如果a1 - an是递增的n个数, 那么他们的和s1, s2, s3…(也是递增), s1 = a1 + a2, s2 = a1 + a3, 那么只要找出a2 + a3, 就可以求出a1了
2. 如何找出a2 + a3呢, 显然它不是s3. 但是我们可以遍历s3直到s(n*(n+1)/2), 假设这个s是a2 + a3, 从而求解出a1
3. OK, 那么假设我们已经求出了a1, 有什么用? 我们可以求出a2, 因为s1是a1和a2的和, 我们在所有和中剔除已知数两两之和(a1, a2), 
剩下的最小s就是a1+a3, 那么可求出a3, 再利用a3将可以求出的s剔除掉, 剩下的s的最小就是a1+a4, 同理, 利用这个规则可以求解出所有的a
4、遇到了不可满足的情况, 就换一个a2+a3, 找到了第一个就可以退出了, 因为题目给出的数据是唯一的而且有解的
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//***warn 可能有相同的sum，所以set容器不太方便 ,multiset可以 
int s[10000], num[105], vis[10000];
multiset<int>ms;

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		int size=n*(n-1)/2;
		int num[size]={0};
		ms.clear(); //warn  初始化 
		for(int i=1;i<=size;i++) 
		{
			cin>>s[i];
			ms.insert(s[i]);
		}

		for(int i=3;i<=size;i++)
		{
			if((s[1]+s[2]-s[i])%2==1||(s[1]+s[2]-s[i]<=0)) continue; //正整数 ****warn：|| not && 
			num[1]=(s[1]+s[2]-s[i])/2;
			num[2]=s[1]-num[1];
			num[3]=s[2]-num[1];
			multiset<int>t=ms;
			vector<int>ans;
			ans.push_back(0);
			for(int j=1;j<=3;j++) ans.push_back(num[j]); //***warn*** j
			for(int j=1;j<=2;j++) t.erase(s[j]);
			t.erase(t.find(s[i]));
			int flag=1; //已知
			while(ans.size()<n+1) //warn <
			{
				int mn=*t.begin();  //这里最小值实际上就是a1+a4,a1+a5...等 
				ans.push_back(mn-num[1]);
				t.erase(t.begin()); //warn
				//从s[]中删去他们的和
				for(int j=2;j<=ans.size()-2;j++) //warn: 已知数==ans.size()-1
				{			//<=size-2
					int temp=ans[j]+ans[ans.size()-1];

					if(t.find(temp)==t.end()) //没找到 
					{
						flag=0;
						break;
					}
					else t.erase(t.find(temp));  //只删一个 
//					else t.erase(temp); //warn****这么直接把2个987一起删了 
				} 
				if(!flag) break;
			}
			if(ans.size()!=n+1&&!flag) continue; //前面塞了一个0 
			for(int j=1;j<=n;j++) cout<<ans[j]<<" "; //j
			cout<<endl;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
} 
