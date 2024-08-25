#include<iostream>
#include<map>
using namespace std;
int main(){
	map<string,int>hyue={{"pop",0},{"no",1},{"zip",2},{"zotz",3},{"tzec",4},{"xul",5},{"yoxkin",6},{"mol",7},{"chen",8},{"yax",9},{"zac",10},{"ceh",11},{"mac",12},{"kankin",13},{"muan",14},{"pax",15},{"koyab",16},{"cumhu",17},{"uayet",18}};//h历法的月份对应
	string tyue[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};//t历法的月份对应
	int n;cin>>n;
	while(n--){
		int sum=0;
		string a;
		cin>>a;
		int hday=stoi(a);//字符串转int，会自动删掉非字符部分
		int hmonth=hyue[a.substr(a.find('.')+1)];
		int hyear;cin>>hyear;
		sum=hyear*365+hmonth*20+hday;//换算成天数
		int tyear=sum/260;
		string tmonth=tyue[sum%20];
		int tday=sum%13+1;
		cout<<tday<<" "<<tmonth<<" "<<tyear<<endl;	
		}
}

