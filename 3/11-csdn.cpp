//看到这种方法的我直接Σ(っ °Д °;)っ
//模拟笔画是计算机做的事儿，但人脑可以直接搞个转换矩阵出来
//map容易出错
#include <iostream>
#include <vector>
using namespace std;
int main() {
	bool map[10][10] = {
		{1, 1, 0, 0, 0, 0, 0, 1, 1, 0},//0
		{1, 1, 0, 1, 1, 0, 0, 1, 1, 1},//1
		{0, 0, 1, 0, 0, 0, 0, 0, 1, 0},//2
		{0, 1, 0, 1, 0, 0, 0, 1, 1, 1},//3
		{0, 1, 0, 0, 1, 0, 0, 0, 1, 1},//4
		{0, 0, 0, 0, 0, 1, 1, 0, 1, 1},//5
		{0, 0, 0, 0, 0, 1, 1, 0, 1, 0},//6
		{1, 1, 0, 1, 0, 0, 0, 1, 1, 1},//7
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//8
		{0, 1, 0, 1, 1, 1, 0, 1, 1, 1} //9
	};
	vector<int> vec(10);
	bool flag = 1;
	while (1) {
		flag = 1;
		cin >> vec[0];
		if (vec[0] == -1) {
			break;
		}
		for (int i = 1; i < 10; i++) {
			cin >> vec[i];
			if (!map[vec[i]][vec[i - 1]]) {
				flag = 0;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}


