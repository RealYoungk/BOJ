#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;	// N(1~10), K(1~100,000,000[¾ï])
vector<int> coin;

bool compare(int a, int b) {
	return a > b;
}

int howManyCoin(int k) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		temp = k / coin[i];
		k = k % coin[i];
		result = result + temp;
	}
	return result;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int size;
		cin >> size;
		coin.push_back(size);
	}
	sort(coin.begin(), coin.end(), compare);
	cout << howManyCoin(K);
}