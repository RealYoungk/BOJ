#include<iostream>
using namespace std;

int N;
int result = 0;
int col[15];

bool check(int i) {
	for (int j = 0; j < i; j++) {
		if(col[i] == col[j] || abs(col[i]-col[j]) == (i-j))
			return false;
	}
	return true;
}

void backTracking(int i) {
	if (i == N) result++;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;
			if (check(i)) {
				backTracking(i + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	backTracking(0);
	cout << result;
	return 0;
}