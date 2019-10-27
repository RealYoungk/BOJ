#include<iostream>
using namespace std;
#define pay 1000

int howManyCoin(int n) {
	int n500 = 0, n100 = 0, n50 = 0, n10 = 0, n5 = 0, n1 = 0;
	if (n >= 500) {
		n500 = n / 500;	n = n - n500 * 500;
	}
	if (n >= 100) {
		n100 = n / 100;	n = n - n100 * 100;
	}
	if (n >= 50) {
		n50 = n / 50;	n = n - n50 * 50;
	}
	if (n >= 10) {
		n10 = n / 10;	n = n - n10 * 10;
	}
	if (n >= 5) {
		n5 = n / 5;	n = n - n5 * 5;
	}
	if (n >= 1) {
		n1 = n / 1;	n = n - n1 * 1;
	}
	return n500 + n100 + n50 + n10 + n5 + n1;
}

int main() {
	int price;
	cin >> price;
	cout << howManyCoin(pay - price);
}