#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d %d %d", &n,&a,&b);
    string s;
    cin>>s;
    int dp[5001];
    dp[0]=0;dp[1]=a;
    for(int i=2;i<=n;i++)
        dp[i]=999999999;
    for(int l=2;l<=n;l++){
        string ss = s.substr(0,l);//长度l的子串
        dp[l] = dp[l-1]+a;
        for(int mid=(l+1)/2;mid<l;mid++){//左半一定是长于右半的，所以mid从(l+1)/2开始
            string left=ss.substr(0,mid);//子串左半
            string right=ss.substr(mid,l);//子串右半
            if(left.find(right)!=left.npos)
                dp[l] = min(dp[l], dp[mid]+b);
        }
    }
    cout<<dp[n];
}
