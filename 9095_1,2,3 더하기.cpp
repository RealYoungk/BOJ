#include<iostream>

using namespace std;

int result[12] = {0,1,2,4,};	// 0~11, 0�� ��� ����

int main() {
	
	int count;
	cin >> count;
	while (count--) {
		int n;
		//cout << "������ �Է��� �ּ��� : ";
		cin >> n;

		for (int i = 4; i < 12; i++) {
			result[i] = result[i - 1] + result[i - 2] + result[i - 3];
		}

		cout << result[n] << '\n';
	}
	return 0;
}