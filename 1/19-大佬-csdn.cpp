#include<bits/stdc++.h>
using namespace std;
int m;
struct P{
    char id[19];                 
    int social;                   
    int area;                      
    char date[11];             
    bool operator < (const P&b)const{  //NB 直接重载运算符 
    	if(area==0&&social<=24)return 0;
    	if(b.area==0&&b.social<=24)return 1;
		if(area!=b.area)return area<b.area; //包含了 0<b.area  
		if(area==0&&social!=b.social)return social>b.social; //都是0 且社保不相等 
		for(int i=6;i<10;++i)
    		if(date[i]!=b.date[i])return date[i]<b.date[i];
    	for(int i=0;i<2;++i)
       	 	if(date[i]!=b.date[i])return date[i]<b.date[i];
  	 	for(int i=3;i<5;++i)
        	if(date[i]!=b.date[i])return date[i]<b.date[i];
        return 0;
	}
};
P *p;
P *getMess(int &n){
    FILE *fp;
    fp=fopen("house.bin","rb");
    fseek(fp,-1*(long)sizeof(int), 2);
    fread(&n, sizeof(int),1, fp);
    rewind(fp);
    P *tmp=new P[n];
    fread(tmp, sizeof(P), n, fp);
    fclose(fp);
    return tmp;
}
int n;
map<string,int>mp;
void work(){
	char c[19];
	scanf("%s",c);
	string s=c;
	int id=mp[s];
	int l=lower_bound(p,p+n,p[id])-p+1;  //二分查找  //（大于）等于她的第一个人的下标+1  即他的排名 
	int r=upper_bound(p,p+n,p[id])-p; //大于她的人的第一个下标  //前一个人（资格等于她）的排名 
	if((p[id].area==0&&p[id].social<=24)||l>m)printf("Sorry\n");
	else if(l==r)printf("%d\n",l);
	else r>m?printf("%d/%d\n",m-l+1,r-l+1):printf("%d %d\n",l,r);
}
int main(){
	p=getMess(n);
	sort(p,p+n); //NB 
	for(int i=0;i<n;++i){
		string s=p[i].id;  //char[] 可直接赋值给string 
		mp[s]=i; //记录下标 
	}
	int T;
	scanf("%d%d",&m,&T);
	while(T--)work();
	return 0;
}
