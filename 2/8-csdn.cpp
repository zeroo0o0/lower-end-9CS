#include<iostream>
using namespace std;
int dir_x[4]={0,1,0,-1};
int dir_y[4]={1,0,-1,0};
int main(){
	int n;
	cin>>n;
	int x=(n-1)/2,y=(n-1)/2;//计算出初始位置 
	int map[n][n];//地图 
	int dir_flag=0;//控制方向 
	int buchang=1;//该方向跑几次 
	int buchang_cnt=0;//buchang 计数，两次增加一次 
	int i=1;//赋值的数字 
	map[x][y]=1;
	while(i<n*n){

		for(int j=1;j<=buchang;j++){
			map[x+j*dir_x[dir_flag]][y+j*dir_y[dir_flag]]=++i;
			if(i==n*n) break;
		}
		x=x+buchang*dir_x[dir_flag];//更新到本方向的终点坐标 
		y=y+buchang*dir_y[dir_flag];//更新到本方向的终点坐标
		buchang_cnt++;
		if(buchang_cnt==2){//找规律，某一个buchang走两次就增加了 
			buchang_cnt=0;
			buchang++;
		} 
		dir_flag++;//该方向走完走下一个方向 
		if(dir_flag==4) dir_flag=0;//方向循环了 
	}
	for(int i=0;i<n;i++ ){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 

