#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct newRecruits {
	int a;
	int b;
};

vector<newRecruits> candidate;
vector<newRecruits> candidate2;
vector<newRecruits> pass;

bool compareA(newRecruits p1, newRecruits p2) {
	return p1.a < p2.a;
}

bool compareB(newRecruits p1, newRecruits p2) {
	return p1.b < p2.b;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int newRecruitsNum;
		newRecruits r;
		cin >> newRecruitsNum;
		while (newRecruitsNum--) {
			cin >> r.a >> r.b;
			candidate.push_back(r);
		}

		sort(candidate.begin(), candidate.end(), compareA);
		r = candidate[0];

		for (int i = 0; i < candidate.size(); i++) {
			if (r.b >= candidate[i].b) {
				pass.push_back(candidate[i]);
				r.a = candidate[i].a; r.b = candidate[i].b;
			}
			else {
				candidate2.push_back(candidate[i]);
			}
		}

		sort(candidate2.begin(), candidate2.end(), compareB);
		r = candidate[0];

		for (int i = 0; i < candidate2.size(); i++) {
			if (r.a >= candidate2[i].a) {
				pass.push_back(candidate[i]);
				r.a = candidate2[i].a; r.b = candidate2[i].b;
			}
		}

		cout << pass.size() << '\n';

		candidate.clear();
		candidate2.clear();
		pass.clear();
	}
}