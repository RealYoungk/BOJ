#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> maps) { // map 1000x1000 , 알파벳 대문자,.
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int beside = 0, biggest[26];
	vector<int> answer;
	bool contry[26][26];    // 0~26 A~Z
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			contry[i][j] = false;
		}
	}
	// 1000x1000 alloc

	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].size(); j++) {
			if (maps[i][j] != '.') {
				for (int k = 0; k < 4; k++) {
					if (i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < maps.size() && j + dy[k] < maps[i].size()) {
						if (maps[i + dx[k]][j + dy[k]] != '.') {
							char findContry = maps[i + dx[k]][j + dy[k]] - 'A';
							contry[maps[i][j] - 'A'][findContry] = true;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		int temp = 0;
		for (int j = 0; j < 26; j++) {
			if (contry[i][j] == true && i!=j) {
				temp++;
			}
		}
		beside = beside + temp;
		biggest[i] = temp;
	}

	int max = biggest[0];
	for (int i = 0; i < 26; i++) {
		if (biggest[i] > max) {
			max = biggest[i];
		}
	}

	answer.push_back(beside / 2);
	answer.push_back(max);
	return answer;
}

int main() {
	vector< string > maps;
	maps.resize(1000);
	maps[0] = "..........";
	maps[1] = "AAACC.....";
	maps[2] = ".AAA.....Z";
	maps[3] = "..AAAA..C.";
	maps[4] = "...BBBBB..";
	maps[5] = "....BBB...";
	maps[6] = "...ZBBB...";
	maps[7] = "ZZZZAAAC..";
	maps[8] = ".....CCCC.";
	maps[9] = "QQ......C.";
	maps[10] = "..........";

	solution(maps);

	return 0;
}