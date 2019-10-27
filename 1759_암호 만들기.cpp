#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct password {
	string pw;
	int mo;	// 모음의 개수
};

struct key {
	char alpha;
};

vector<password> p;
vector<key> k;

int L, C;	// L은 비밀번호 수, C는 비밀번호 후보 문자 수

bool compare(key a, key b) {
	if (a.alpha >= b.alpha) {
		return false;
	}
	else if (a.alpha < b.alpha) {
		return true;
	}
}

void backtracking(int now, string s, int j, int m) {
	if (s.size() == L) {
		if (j < 2 || m < 1) {
			return;
		}
		cout << s << '\n';
		return;
	}
	for (int i = now; i < C; i++) {
		if (k[i].alpha == 'a' || k[i].alpha == 'e' || k[i].alpha == 'i' || k[i].alpha == 'o' || k[i].alpha == 'u') {
			backtracking(i + 1, s + k[i].alpha, j, m + 1);
		}
		else {
			backtracking(i + 1, s + k[i].alpha, j + 1, m);
		}
	}
}

int main() {
	
	cin >> L >> C;

	key tmp;
	for (int i = 0; i < C; i++) {
		cin >> tmp.alpha;
		k.push_back(tmp);
	}

	sort(k.begin(), k.end(), compare);

	backtracking(0, "", 0, 0);

	return 0;
}