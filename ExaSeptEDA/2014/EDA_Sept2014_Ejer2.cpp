#include<iostream>

using namespace std;


// pre: n>= 0 && abs(x) < 1
float serie(float x, int n) {

	float sum = x;
	float pot = x;
	int div = 1;

	for (int i = 1; i < n; i++) {

		pot = pot * x * x;
		div += 2; 
		sum = sum + (pot / div);
	}
	return sum; 
}

// pos: SUM i : 0<= i < n : x^(2*i + 1) / 2*i +1 

// INV: 0 <= k < n && SUM i : 0<= i <= K : x^(2*i + 1) / 2*i +1 

int main() {

	float x = -0.9;
	int n = 20; 

	cout << serie(abs(x), n) << endl;

	system("Pause");
	return 0; 
}