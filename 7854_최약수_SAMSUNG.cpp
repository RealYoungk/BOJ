#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int memo[1000000];

vector <int> sigma;
int max_num;

int findMaxNum() {
	int result = 987654321;
	for (int i = 0; i < sigma.size(); i++) {
		if (result < sigma[i]) {
			result = sigma[i];
		}
	}
	return
}

long long pow(int base, int exponent, int start) {
	long long result = 1;
	for (int i = start; i <= exponent; i++) {
		result = result * base;
		result = result % 1000000007;
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		sigma.push_back(N);

	}



	int N = findMaxNum();
	long long result = 0;
	long long temp = 0;

	for (int i = 1; i <= N; i++) {

		temp = pow(i, i);
		temp = temp % 1000000007;
		result = result % 1000000007 + temp % 1000000007;
		memo[i] = result;

	}

	for (test_case = 1; test_case <= T; test_case++) {

		for (int i = 0; i < sigma.size(); i++) {

			cout << "#" << test_case << " " << memo[sigma[i]] << '\n';

		}

	}
	return 0;
}