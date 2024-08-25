#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
/******************将字符串全部转换为小写的函数************************/
string to_lower(string str){
	for(int i=0;i<str.length();i++){
		if(isupper(str[i])){
			str[i]=tolower(str[i]);
		}
	}
	return str;
}
/******************将字符串切割为单词存储到map,方便查询************************/
map<string,int> to_word_map(string str){
	map<string,int> temp;
	stringstream ss;
	ss<<str;
	while(ss>>str){
		temp[str]=1;
	} 
	return temp;
}
/******************将字符串切割为单词存储到vector,方便查询************************/
vector<string> to_word_vector(string str){
	vector<string> temp;
	stringstream ss;
	ss<<str;
	while(ss>>str){
		temp.push_back(str);
	} 
	return temp;
}
/*****************************论文结构体*******************************/
struct paper{
	map<string,int> name;//忽略大小写，用于查询 
	string true_name; 
	int quote;
}; 
/***************************vector排序规则*****************************/
bool cmp(paper a,paper b){
	return a.quote>b.quote;
} 
int main(){
	int n,k;
	while(cin>>n){
		if(!n) break; 
		vector<paper> res;
		while(n--){
			paper temp;
			cin.ignore();//忽略换行符 
			getline(cin,temp.true_name);//获取整行字符串 
			temp.name=to_word_map(to_lower(temp.true_name));//转换为小写再切割单词存到map
			cin>>temp.quote;
			res.push_back(temp);
		} 
		sort(res.begin(),res.end(),cmp);//先进行排序后再查询出来的结构自然是排序的 
		cin>>k;
		cin.ignore();
		while(k--){
			string check;//bug：未忽略空行 
			getline(cin,check);
			check=to_lower(check);
			/**********************查询比较麻烦，不能直接find**************************/ 
			/**********************所以我们要做一个单词切割****************************/ 
			vector<string> check_word=to_word_vector(check);//切割存储到vector
			for(int i=0;i<res.size();i++){//遍历排序好的论文 
				int j;
				for(j=0;j<check_word.size();j++){//一个单词一个单词的去找 
					if(res[i].name.find(check_word[j])==res[i].name.end())	
						break;
				} 
				if(j==check_word.size()) cout<<res[i].true_name<<endl; //如果每个单词都找到了就输出 
			}
			cout<<"***"<<endl;	
		} 
		cout<<"---"<<endl;		
	}
	return 0;
} 
