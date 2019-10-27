#include<iostream>
using namespace std;
int N, M, K;
int total;
int group = 0;
int contestOrIntern() {
	for (int i = 0; i < total / 3; i++) {
		if (N <= 1 || M <= 0) {
			return group;
		}
		N = N - 2;
		M = M - 1;
		group++;
	}
	return group;
}

int main() {
	cin >> N >> M >> K;
	total = N + M - K;
	cout << contestOrIntern();
}