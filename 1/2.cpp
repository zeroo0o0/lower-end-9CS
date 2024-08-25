#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010;
int l[N];
int n, m;

int main() {

	cin >> n >> m;
	
	char a[n][m];
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
			// 当前位是1，代表可以 i 开关可以开 j 灯 
			if (a[i][j] - '0') l[j] ++;
		} 
	
	bool flag = false;
	for (int i = 0; i < n; i ++) {
		int k = 0;
		for (int j = 0; j < m; j ++) 
			// 减去某一个灯外，剩下的灯的数组都不为0，表示还有其他的开关 
			if (l[j] + '0' - a[i][j] > 0)  k ++;
		
		// 找到了可以去除的那一个开关
		if (k == m) {
			flag = true;
			break;
		}
	}
	
	if (flag) puts("YES");
	else puts("NO"); 
	
	return 0;
}

