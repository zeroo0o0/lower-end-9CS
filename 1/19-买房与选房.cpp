#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int m; 
int n;                            /* n为报名人数，通过调用函数getMess获取 */
map<string,int>mp;
struct people
{
	char id[19];                  /* 身份证号码 */
	int social;                     /* 社保缴纳月数 */
	int area;                       /* 现有住房面积 */
	char date[11];              /* 申报日期 */
	
	//***重载< 
	bool operator<(const people b)const  //底层要求 用const 且（）后有const修饰符 
	{
		if(area==0&&social<=24) return false;
		if(b.area==0&&b.social<=24) return true;
		if(area!=b.area) return area<b.area;
		if(area==0&&social!=b.social) return social>b.social;
		for(int i=6;i<=9;i++)
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		for(int i=0;i<=1;i++)   //warn  注意日期格式  月--日--年
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		for(int i=3;i<=4;i++)    
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		return 0; //warn 不能return true 否则WA 
	}
};
people *p;          /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */

people* getMess(int &n)            /* 将文件数据读入内存 */
{									//读取已经完成 
	FILE *fp;
	fp=fopen("house.bin","rb");
	fseek(fp,-1*(long)sizeof(int), 2);
	fread(&n, sizeof(int),1, fp);
	rewind(fp);
	people *tmp=new people[n];
	fread(tmp, sizeof(people), n, fp);
	fclose(fp);
	return tmp;
}

void solve()
{
	string s; cin>>s;
	int id=mp[s];
	int l=lower_bound(p,p+n,p[id])-p+1; //==的 第一个 排名
	int r=upper_bound(p,p+n,p[id])-p; //==的 最后一个排名
	if((p[id].area==0&&p[id].social<=24)||l>m) cout<<"Sorry"<<endl;
	else if(l==r) cout<<l<<endl;
	else if(r>m) cout<<m-l+1<<"/"<<r-l+1<<endl; //warn r-l not r-m
	else cout<<l<<" "<<r<<endl; 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	p=getMess(n);
	// ...
	sort(p,p+n);
	for(int i=0;i<n;i++)
	{
		string s=p[i].id;
		mp[s]=i;  
	}
	int t; cin>>m>>t;
	while(t--) solve(); 
	return 0;
}
