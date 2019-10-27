#include<iostream>
#include<string>
using namespace std;

int dp[50001];

int main() {

	int num;
	cin >> num;

	// 223 * 223 = 49729
	for (int i = 1; i < 224; i++) {
		dp[i * i] = 1;
	}

	for (int i = 1; i < 224; i++) {
		for (int j = i * i + 1; j < (i + 1) * (i + 1); j++) {
			int temp = j;
			dp[temp] = dp[i * i] + dp[temp - i * i];
			for (int k = i; k >= 1; k--) {
				if (dp[temp] > dp[k * k] + dp[temp - k * k]) {
					dp[temp] = dp[k * k] + dp[temp - k * k];
				}
			}
		}
	}

	cout << dp[num];
	return 0;
}