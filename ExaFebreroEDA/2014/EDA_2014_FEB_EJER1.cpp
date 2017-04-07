#include<iostream>

using namespace std;

const int N = 10;

int main() {

	int m = 3;
	int s = 10;
	int max = 10;
	int v[N] = { 5,-4,9,7,-5,6,-1,10,0,3 };

	for (int i = m; i < N; i++) {

		s += v[i];
		s -= v[i - m];

		if (s > max) max = s;
	}

	cout << max << endl;

	system("PAUSE");
	return 0;
}