#include <bits/stdc++.h>
using namespace std;
 
bool nrev(string s)
{
	int n = s.size()/2;
	int a=0, b=s.size()-1;
	for (int i=0; i<n; i++) {
		if (s[a]!=s[b]) return 1;
		a++, b--;
	}
	return 0;
}
 
int main()
{
	int n, c;
	while (cin >> n) {
		if (!n) return 0;
		string s, u, t; cin >> s;
		c = -1;
		do {
			u=s; t = u.substr(0, c+1); 
			reverse(t.begin(), t.end()); 
			u+=t; c++;
		} while (nrev(u)); 
		cout << c << endl;
	}	
}
