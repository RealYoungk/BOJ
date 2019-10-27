#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string N;
int sum = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		sum = sum + (N[i] - '0');
	}
	sort(N.begin(), N.end());
	if (N[0] == '0' && (sum % 3) == 0) {
		reverse(N.begin(), N.end());
		cout << N;
	}
	else {
		cout << "-1";
	}
	return 0;
}