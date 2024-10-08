#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
	int left;//占座起点 
	int right;//占座终点 
}temp;
int main(){
	int n,m;
	vector<int> position;
	map<int,node> map;
	while(cin>>n>>m){	
		for(int i=0;i<n*n;i++){
			position.push_back(0);//0表示座位没人 
		}
		int k;//命令个数 
		int id,num;//记录id和需要的num座位数
		cin>>k;
		while(k--){
			string order;
			cin>>order;
			int flag=0;//控制输出yes no 
			if(order[0]=='i'){
				cin>>id>>num;
				if(map.find(id)==map.end()){//之前没占过才可以占座 
					for(int i=0;i<=n*n-num;i++){
						int j;
						for(j=i;j<i+num;j++){
							if(position[i]==0) continue;
							else break;
						}
						if(j==i+num&&!position[i+num-1]){//找到了连坐 
							temp.left=i;
							temp.right=i+num-1;
							map[id]=temp; 
							cout<<"yes"<<endl;
							flag=1;
							/************连坐占座***************/
							for(int k=temp.left;k<=temp.right;k++){
								position[k]=1;
							} 
							break;
						}
					}					
				}
			}else{
				cin>>id;
				if(map.find(id)!=map.end()){
					for(int i=map[id].left;i<=map[id].right;i++){
						position[i]=0;//座位腾空 
					}
					map.erase(map.find(id));
					cout<<"yes"<<endl;
					flag=1;
				}
			}
			if(!flag) cout<<"no"<<endl;
		} 
	}
	return 0;
} 

