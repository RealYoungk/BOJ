#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");
int M, N, K, result;
bool grid[50][50];
bool visit[50][50];
int dx[4] = { -1, 0 ,1 ,0 };
int dy[4] = { 0, -1, 0, 1 };


void init() {
	result = 0;
	memset(grid, false, sizeof(grid));
	memset(visit, false, sizeof(visit));
	//fin >> M >> N >> K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		//fin >> a >> b;
		grid[a][b] = true;
	}
	return;
}

void dfs(int m, int n) {

	if (m < 0 || n < 0 || m >= M || n >= N) return;
	
	visit[m][n] = true;

	for (int i = 0; i < 4; i++) {
		int x = m + dx[i];
		int y = n + dy[i];
		if (!visit[x][y] && grid[x][y]) {
			dfs(x, y);
		}
	}
}

int main() {

	int testcase;
	cin >> testcase;
	//fin >> testcase;
	while (testcase--) {
		init();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j] && grid[i][j]) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';
//		fout << result << '\n';
	}

	return 0;
}
