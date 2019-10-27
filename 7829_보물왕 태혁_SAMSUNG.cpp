#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

vector < int > measure;	// 약수들의 배열
ifstream fin("input.txt");
ofstream fout("output.txt");

bool compare(int a, int b) {
	return a < b;
}

int main() {

	int testcase;
	fin >> testcase;

	for (int t = 1; t <= testcase; t++) {

		int measure_num;	// 약수의 개수
		fin >> measure_num;

		int temp;
		for (int i = 0; i < measure_num; i++) {
			fin >> temp;
			measure.push_back(temp);
		}

		sort(measure.begin(), measure.end(), compare);

		fout << "#" << t << " " << measure[0] * measure[measure.size() - 1] << '\n';

		measure.clear();
	}

	return 0;
}