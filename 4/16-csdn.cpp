#include<string>
#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
 
/*
这道题想了挺久  主要是知道a1+a2,a1+a3  但是怎么找到a2+a3呢？
计算机-->【遍历】来寻找验证，答案唯一，找到就是正确的 
本身数据量是不大的：N < 100 
*/
 
int sum[10200]; //和 数组 
int vis[10200]; //访问和的数组 
int num[110];   // 原数字 
 
 int main(){
 	int n;
 	while(cin>>n&&n){
 		int size=(n*(n-1))/2;
		 for(int i=1;i<=size;i++){  //下标从1开始 
		 	cin>>sum[i];
		 }	
 
		 for(int i=3;i<=size;i++) {     //循环很多次，暴力穷举！ 假设sum【i】是a2+a3，
		 								//如果，sum全被访问了，说明sum【i】就是a2+a3，否则继续遍历 
		 	//num[1]+num[2]=sum[1];
			//num[1]+num[3]=sum[2];
			//num[2]+num[3]=sum[i];   这里假设sum[i]是a2+a3,推出a4，a5，an……能全部推出来，就是答案 
		 	
		 	num[1]=(sum[1]+sum[2]-sum[i])/2;
		 	num[2]=sum[1]-num[1];
			num[3]=sum[2]-num[1]; 
			
			if (( sum[1]+ sum[2] - sum[i]) % 2 || (sum[1] + sum[2] - sum[i] <= 0)) 
                continue; // 2*a1肯定不是奇数   a1一定是正整数....不然得出来一组非整数解 
			
			memset(vis,0,sizeof(vis));//每次都要把mark数组清0，检验当前的sum[i]是不是a2+a3
			
			vis[1]=vis[2]=vis[i]=1;  //标记 和1，2，i都已经被访问过
			
			//这个时候，没有被访问的和中，最小的就是a1+a4,然后求出a4,标记a1+a4,a2+a4,a3+a4;这个时候最小的就是a1+a5…… 
		 	int know=3; //目前已经知道的数
			int flag=1;
			while(know!=n){
			 	int mini=-1;//在没被访问的数字里找到最小值，由于有序，没被访问的第一个就是最小值 
				 for(int j=1;j<=size;j++){
				 	if(vis[j]==0){
				 		mini=sum[j];
				 		vis[j]=1;//标记访问，这里最小值实际上就是a1+a4,a1+a5...等 
				 		break; 
					 }
				 }
			 	
			 	num[know+1]=mini-num[1];
			 	know++; 
			 	
			 	//这里是2~(know-1)  因为a1+aj已经被标记过了
			 	for(int k=2;k<=know-1;k++) { //找到了新的数字，把之前找到的数字和新数字相加，从sum中去去除 
			 		int temp=num[k]+num[know];
			 		flag=0;
					 for(int p=1;p<=size;p++){
			 			if(vis[p]==0 && sum[p]==temp){
			 				flag=1;
			 				vis[p]=1;
			 				break;
						 }
					 }
					 if(flag==0) break;  //如果相加出来的值找不到，那说明一开始a2+a3找错了 
				 }
			 	if(flag==0) break;
			 } 	
			 //while循环正常或者不正常结束了...
			 if(know!=n) continue;   //这个sum[i]不对，继续for循环找下一个
			 
			 for(int h=1;h<=n;h++){  //找到了 
			 	cout<<num[h]<<" ";
			 }
			 cout<<'\n';
			 break;  
		} 	 	
	} 	
}
	
