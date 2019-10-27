#include<iostream>
#include<algorithm>
using namespace std;

int N;			// 사람의 수(1~1000)
int P[1000];	// 인출하는데 걸리는 시간(1~1000)
int result = 0;	// 인출시간의 총 합

void atm() {
	sort(P, P + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			result = result + P[j];
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i];
	atm();
	cout << result;
	return 0;
}