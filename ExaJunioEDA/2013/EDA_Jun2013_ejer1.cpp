#include<iostream>

using namespace std;


// pre: 0<= N <= long(v) 
int resuelve(int N, int v[], int x) {

	int sum = 0;
	int fComun = 1;

	for (int i = 0; i < N; i++) {

		sum += v[i] * fComun;
		fComun = fComun*x;
	}

	return sum;
}
// pos: sum = SUMATORIO i: 0<= i < N : V[i] * X elevado i

// INV: 0 <= n <= N && sum = SUMATORIO i: n<= i < N : V[i] * X elevado i

int main() {

	const int N = 6;
	int v[N] = {1, 2, 3, 4, 5, 6};
	int x = 2;

	cout << resuelve(N, v, x) << endl;

	system("pause");
	return 0;
}