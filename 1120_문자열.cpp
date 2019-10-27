#include<iostream>
#include<string>
using namespace std;

int main() {
	string x, y;
	int result = 987654321;
	cin >> x >> y;
	int num = y.size() - x.size();
	for (int i = 0; i <= num; i++) {
		int tmp = 0;
		int min_temp;
		for (int j = i, k = 0; k<x.size(); j++,k++) {
			if (x[k] != y[j]) {
				tmp++;
			}
		}
		if (tmp < result) { result = tmp; }
	}
	cout << result;
}