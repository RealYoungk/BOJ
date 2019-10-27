#include<iostream>
#include<algorithm>
using namespace std;

int rope[100000];
int K;
int W;

int howManyWeight() {
	int max = 0;
	int tmp = 0;
	for (int i = 0; i < K; i++) {
		tmp = rope[i] * (K - i);
		if (max < tmp) max = tmp;
	}
	return max;
}

int main() {
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + K);
	W = howManyWeight();
	cout << W;
	return 0;
}