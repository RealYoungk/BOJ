#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int N;	// 1<=N<=80
string sequence;	// ¼ö¿­

int backtracking(int here) {
	//	1
	for (int i = 1; i <= here / 2; i++) {
		if (equal(sequence.end() - i, sequence.end(), sequence.end() - i * 2)) {
			return -1;
		}
	}
	//	2
	if (here == N) {
		cout << sequence;
		return 0;
	}
	//	3
	for (int i = 1; i <= 3; i++) {
		sequence.push_back(i + '0');
		if (backtracking(here + 1) == 0)
			return 0;
		sequence.pop_back();
	}
}

int main() {

	cin >> N;

	backtracking(0);

}