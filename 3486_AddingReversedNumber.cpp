#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int testcase;
vector<int> v;

int getLastInt(int &num) {
	int result = num % 10;
	num = num / 10;
	return result;
}

int reverse(int num) {
	long result = 0;
	for (int i = 0; i < 9; i++) {
		v.push_back(getLastInt(num));
		if (num == 0) break;
	}
	// 반전된 숫자는 뒤에 0이오는것을 가지지 않는다
	int size = v.size();
	for (int i = size - 1, j = 0; i >= 0; i--, j++) {
		result = result + v[j] * pow(10, i);
	}
	v.clear();
	return result;
}

int main() {
	int num1, num2;
	cin >> testcase;
	while (testcase--) {
		cin >> num1 >> num2;
		cout << reverse(reverse(num1) + reverse(num2)) << '\n';
	}
}