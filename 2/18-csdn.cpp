#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int> > map(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			map[i].push_back(ch-'0');
		}
	}
	int ans=1;//矩阵至少包含一个1字符; 
	int cnt=1;//至少一个 
	for(int size=1;size<=n;size++){ //最大尺寸的遍历 
		int temp_cnt=0;
		for(int i=0;i<=n-size;i++){
			for(int j=0;j<=n-size;j++){ //i,j 起点 
				/*************上面两层for循环用来遍历所有的该size棋盘*******************/
				/************************对每个棋盘进行check****************************/
				int k,l;
				for(k=0;k<size;k++){
					int flag=0;
					for(l=0;l<size;l++){
						if((l+k)%2==0){
							if(map[i+k][j+l]==1) continue;
							else {
								flag=1;break;
							}
						}else{
							if(map[i+k][j+l]==0) continue;
							else {
								flag=1;break;
							}
						}
					}
					if(flag) break;
				} 
				/**************如果跑完说明棋盘符合要求*********************************/
				if(k==size&&l==size){
						ans=size;
						temp_cnt++;
				}
			}
		}
		if(ans!=size) break; //当前size没有找到ans，所以更大的size也找不到，后面就不找了
		if(ans==size) cnt=temp_cnt;//如果找到了ans，我们更新找到的个数 
		
	} 
	cout<<ans<<" "<<cnt<<endl; 
	return 0;
} 


