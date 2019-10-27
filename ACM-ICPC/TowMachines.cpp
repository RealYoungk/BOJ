#include<iostream>
#include<algorithm>
using namespace std;

struct Task {
	int a;
	int b;
	int id;
	Task() {
		id = 0;
	}
};

bool visit[250];
Task t[250];
Task t2[250];
int n;

bool isEnd() {
	for (int i = 0 ; i < n; i++) {
		if (visit[i] == false) {
			return false;
		}
	}
	return true;
}

bool CompareA(Task t1, Task t2) {
	if (t1.a > t2.a) {
		return true;
	}
	else if (t1.a < t2.a) {
		return false;
	}
	else {
		if (t1.b > t2.b) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool CompareB(Task t1, Task t2) {
	if (t1.b > t2.b) {
		return true;
	}
	else if (t1.b < t2.b) {
		return false;
	}
	else {
		if (t1.a < t2.a) {
			return true;
		}
		else {
			return false;
		}
	}
}

int Scaduling() {

	int atime = 0;
	int btime = 0;
	for (int i = 0, j = 0; !isEnd();) {

		if (visit[t[i].id]) {
			i++;
		}
		if (visit[t2[j].id]) {
			j++;
		}

		if (!visit[t[i].id] && !visit[t2[j].id]) {

			if (atime + t[i].a < btime + t2[j].b) {
				atime = atime + t[i].a;
				visit[t[i].id] = true;
				i++;
			}
			else if (atime + t[i].a > btime + t2[j].b) {
				btime = btime + t2[j].b;
				visit[t2[j].id] = true;
				j++;
			}
			else {
				if (t[i].a < t2[j].b) {
					atime = atime + t[i].a;
					visit[t[i].id] = true;
					i++;
				}
				else {
					btime = btime + t2[j].b;
					visit[t2[j].id] = true;
					j++;
				}
			}

		}
		else continue;

	}

	if (atime > btime) {
		return atime;
	}
	else return btime;
}

int main() {

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		t[i].a = a;	t[i].b = b;
		t2[i].a = a; t2[i].b = b;
		t[i].id = i;	t2[i].id = i;
	}

	sort(t, t + n, CompareA);
	sort(t2, t2 + n, CompareB);

	cout << Scaduling();

	return 0;
}