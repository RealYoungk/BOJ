#include<iostream>
//#include<fstream>
using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");

bool graph[101][101];
bool visit[101];
int computer, edge;

void dfs(int n) {
	visit[n] = true;
	for (int i = 1; i <= computer; i++) {
		if (!visit[i] && graph[n][i]) {
			dfs(i);
		}
	}
}

int result() {
	int r = 0;
	for (int i = 1; i <= computer; i++) {
		if (visit[i]) {
			r++;
		}
		//cout << visit[i];
	}
	return r;
}

int main() {
	
	cin >> computer >> edge;
	for (int i = 0; i < edge; i++) {
		int s, e;
		cin >> s >> e;
		graph[s][e] = true;
		graph[e][s] = true;
	}

	dfs(1);

	cout << result() - 1;
	

	return 0;
}