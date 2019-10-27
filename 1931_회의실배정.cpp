#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;	// 회의 수(1~100,000)
int cnt = 0;	// 배정 된 회의 수

struct conference {
	int start;
	int end;
};

vector < conference > v;


bool compare(conference a, conference b) {
	if (a.end < b.end) {
		return true;
	}
	else if (a.end == b.end) {
		if (a.start < b.start) return true;
		else return false;
	}
	else return false;
}

int assign() {
	conference result;
	result.start = 0;	result.end = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].start >= result.end) {
			result.end = v[i].end;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> N;
	conference c;
	for (int i = 0; i < N; i++) {
		cin >> c.start >> c.end;
		v.push_back(c);
	}
	sort(v.begin(), v.end(), compare);

	cout << assign();
}