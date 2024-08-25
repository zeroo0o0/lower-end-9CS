 #include<string>
 #include<iostream>
 #include<sstream>
 #include<stack>
 using namespace std;
 
 int a[100010];
 int path[100010];  //前导数组，用来寻找最长路径 
  int n; //最大层数 
  
 int dp(int now,int now_floor,int fa){
 	
	 if(now_floor==n) {  //到达最底层 
 		return a[now];
	 }
	 
	  int left=a[now] + dp( now+now_floor,now_floor+1, now);
	  int right=a[now]+ dp(now+now_floor+1, now_floor+1, now);
	  path[now]=left>right?now+now_floor:now+now_floor+1;
	  return max(left,right);   
	 //对比走左右两边，哪边更大。左边：结点+层数    右边：结点+层数+1 
 }
 
 
 int main(){
 	
	 cin>>n;
	 int num=((n+1)*n)/2; //总的结点数量 
	 
	 for(int i=0;i<num;i++) cin>>a[i];
	 
	  cout<<dp(0 , 1 , -1)<<'\n';    //当前总和为a[0]，初始结点为0，初始层数为1 
	
	int k=0;
	int f=1;
	while(f<=n){
		cout<<a[k]<<" ";
		k=path[k];
		f++;
	}
 } 
