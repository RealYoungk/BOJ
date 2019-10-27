#include<iostream>
#include<algorithm>
using namespace std;

struct Brand {
	int set;
	int individual;
};

struct Result {
	int r1;
	int r2;
	int r3;
	int r4;
};

int individual[50];
int set[50];
Result r;

bool compare(int a, int b) {
	return a < b;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> set[i] >> individual[i];
	}
	sort(set, set + M);
	sort(individual, individual + M);

	r.r1 = individual[0] * N;
	r.r2 = individual[0] * (N % 6) + set[0] * (N / 6);
	r.r3 = individual[0] * (N % 6) + set[0] * (N / 6);
	r.r4 = set[0] * (N / 6 + 1);

	if (r.r1 <= r.r2 && r.r1 <= r.r3 && r.r1 <= r.r4) {
		cout << r.r1;
	}
	else if (r.r2 <= r.r1 && r.r2 <= r.r3 && r.r2 <= r.r4) {
		cout << r.r2;
	}
	else if (r.r3 <= r.r1 && r.r3 <= r.r2 && r.r3 <= r.r4) {
		cout << r.r3;
	}
	else if (r.r4 <= r.r1 && r.r4 <= r.r2 && r.r4 <= r.r3) {
		cout << r.r4;
	}
}