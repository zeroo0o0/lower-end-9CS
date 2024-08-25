#include<iostream>
#include<string>
#include<list>
using namespace std;
int n,ret=1,red=15,scoreA=0,scoreB=0,hitA=0,hitB=0,loneA=0,loneB=0;
//ret=1,A起手，scoreAB是AB的比赛分数，hitAB是单杆分数，loneAB是单杆超100分次数
list<string> l; //存储比赛记录
list<char> color_l; //彩球击打顺序
void init_list(list<char> &color_l) {
	//黄、绿、咖啡、蓝、粉红、黑
	color_l.push_back('y');
	color_l.push_back('g');
	color_l.push_back('c');
	color_l.push_back('b');
	color_l.push_back('p');
	color_l.push_back('B');
}
int get_ballScore(char ball) {
	switch(ball) {
		case 'r':{
			return 1;
			break;
		}
		case 'y':{
			return 2;
			break;
		}
		case 'g':{
			return 3;
			break;
		}
		case 'c':{
			return 4;
			break;
		}
		case 'b':{
			return 5;
			break;
		}
		case 'p':{
			return 6;
			break;
		}
		case 'B':{
			return 7;
			break;
		}
	}
}
bool check(string s, char goal) {    //比赛记录，目标球
	if(s=="NULL") { //打空直接犯规
		if(ret==1) {    //记录分数，给对方加分
			scoreB+=(get_ballScore(goal)>4?get_ballScore(goal):4);
		}
		else if(ret==-1) {
			scoreA+=(get_ballScore(goal)>4?get_ballScore(goal):4);
		}
		return true;
	}
	string temp=s+" ",left="",right=""; //left为击球情况，right为落球情况
	int pos=temp.find(" ");
	left=temp.substr(0,pos);
	if(pos!=s.size()) { //打中球但是落空的情况要特判
		right=s.substr(pos+1);
	}
	int num=0;
 	if(right!="") { //先处理红球落袋的情况，不管是否犯规，红球一落袋，就不能放回
 		for(int i=0; i<right.size(); i++) {
 			if(right[i]=='r') {
 				for(int j=i+1; j<right.size(); j++) {
 					if(!(right[j]>='0'&&right[j]<='9')) {
 						break;
					 }
					 num=num*10+right[j]-'0';
				 }
				 red-=num;
				 break;
			 }
		 }
	 }
	
	bool flag=false;    //判断是否有别的球被击打或者落袋
	
	for(int i=0; i<left.size(); i++) {	//先来判断击打情况中是否有别的球
		if(!(left[i]>='0'&&left[i]<='9')&&left[i]!=goal) {	//有别的球
			flag=true;
		}
	}
	
	if(right!="") { //再判断落袋情况中是否有别的球
		for(int i=0; i<right.size(); i++) {
			if(!(right[i]>='0'&&right[i]<='9')&&right[i]!=goal) {
				flag=true;
			}
		}
	}
 
	if(flag) {
		int tempScore=0;
		for(int j=0; j<s.size(); j++) { //		?红球是算1分还是算num分?
			if(!((s[j]>='0'&&s[j]<='9')||s[j]==' ')) {
				if(get_ballScore(s[j])>tempScore) {
					tempScore=get_ballScore(s[j]);
				}
			}
		}
		if(ret==1) {    //记录分数，给对方加分
			scoreB+=(tempScore>4?tempScore:4);
		}
		else if(ret==-1) {
			scoreA+=(tempScore>4?tempScore:4);
		}
		return true;
	}
	
	if(right=="") { //未打进最终还是要换人
		return true;
	}
	
	return false;
}
void getScore(string s, char goal) {
	//优先判定不犯规但是没有球落袋的情况
	string temp=s+" ",left="",right=""; //left为击球情况，right为落球情况
	int pos=temp.find(" ");
	left=temp.substr(0,pos);
	if(pos!=s.size()) { //打中球但是落空的情况要特判
		right=s.substr(pos+1);
	}
	if(right=="") {
		return; //没有球落袋，不做任何处理
	}
	int sum=0;
	if(goal=='r') {
		for(int i=1; i<right.size(); i++) {
			sum=sum*10+right[i]-'0';
		}
	}
	else {
  		sum=get_ballScore(goal);
	}
	//总分进行累加
	if(ret==1) {
		scoreA+=sum;
		hitA+=sum;
	}
	else if(ret==-1) {
		scoreB+=sum;
		hitB+=sum;
	}
}
void change(int Ret) {
	if(Ret==1) {    //从A换到B
		if(hitA>=100) {
			loneA++;
		}
		hitA=0;
	}
	else if(Ret==-1) {  //从B换到A
		if(hitB>=100) {
			loneB++;
		}
		hitB=0;
	}
}
void play_color(int* Ret) {
	if(l.empty()) {
		return;
	}
	string s=l.front();
	l.pop_front();
	if(check(s,color_l.front())) {  //犯规了就换人
		change(ret);    //计算单杆得分
		*Ret=-*Ret;
		play_color(&ret);
		return;
	}
	getScore(s,color_l.front());    //自己得分
	color_l.pop_front();    //没有犯规就弹出一个彩球
	play_color(&ret);
}
void play(int* Ret) {
	if(l.empty()) { //比赛打完了
		return;
	}
	if(red==0) {
		play_color(&ret);
		return;
	}
AGAIN:
	string s=l.front(); //拿取第一条比赛记录
	l.pop_front();
	//打红球，先确定是否犯规
	if(check(s,'r')) {
		change(ret);    //计算单杆得分
		*Ret=-*Ret;   //换人
		play(&ret);
		return;
	}
	getScore(s,'r');    //自己得分
	if(l.empty()) {
		return;
	}
	s=l.front();
	l.pop_front();	//接下来打任意彩球，先判定是否犯规
	if(s=="NULL") { //打红球后任意彩球打空，对方加4分
		if(*Ret==1) {
			scoreB+=4;
		}
		else if(*Ret==-1) {
			scoreA+=4;
		}
		change(ret);    //计算单杆得分
		*Ret=-*Ret;
		play(&ret);
		return;
	}
	if(check(s,s[0])) { //把第一个打到的彩球作为目标球
		change(ret);    //计算单杆得分
		*Ret=-*Ret;
		play(&ret);
		return;
	}
	getScore(s,s[0]);
	if(l.empty()) {
		return;
	}
	if(red==0) {
		play_color(&ret);
		return;
	}
	//如果红球还有剩余，则重复上述过程
	goto AGAIN;
 
}
int main() {
	string s="";
	cin>>n;
	cin.get();
	for(int i=0; i<n; i++) {
		l.clear();
		color_l.clear();
		init_list(color_l);     //注意初始化
		red=15; //红球一共有15个
		scoreA=scoreB=hitA=hitB=0;    //A与B开始得分为0
		ret=1; //A先起手
		while(getline(cin,s)) {
			if(s=="-1") {
				break;
			}
			l.push_back(s); //对比赛信息进行记录
		}
		//对储存好的比赛记录进行得分模拟
		play(&ret);
		if(hitA>=100) {
			loneA++;
		}
		if(hitB>=100) {
			loneB++;
		}
		cout<<scoreA<<":"<<scoreB<<endl;
	}
	cout<<loneA<<":"<<loneB<<endl;
	return 0;
}
