#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define LOTTO_SIZE 6
using namespace std;
int keyNum;
vector<int> lotto;
vector<int> candidateKey;
// here : 문자의 길이, count : 선택할 숫자
int backTracking(int start, int depth) {

	if (depth == LOTTO_SIZE) {
		for (int i = 0; i < LOTTO_SIZE; i++) {
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return 0;
	}

	for (int i = start; i < keyNum; i++) {
		lotto.push_back(candidateKey[i]);
		backTracking(i + 1, depth + 1);
		lotto.pop_back();
	}

}

int main() {

	while (1) {
		cin >> keyNum;

		if (keyNum == 0) return 0;

		for (int i = 0; i < keyNum; i++) {
			int temp;
			cin >> temp;
			candidateKey.push_back(temp);
		}

		backTracking(0, 0);
		candidateKey.clear();
		lotto.clear();
		cout << '\n';
	}
}