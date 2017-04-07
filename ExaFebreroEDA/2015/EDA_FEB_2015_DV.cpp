#include<iostream>

using namespace std;

/*La imagen especular de un número natural es el número que resulta al invertir el
orden de sus dígitos.Por ejemplo, la imagen especular de 13492 es 29431 y la imagen especular
del 1000 es el 1. Implementa dos algoritmos recursivos, uno nal y otro no nal, que calculen la
imagen especular de un número natural representado como unsigned int.Indicar la llamada
inicial a cada algoritmo con los valores iniciales de cada parámetro.Justica el coste de cada
algoritmo.*/

void imagen(int &num, int &result) {

	result += num % 10;
	num = num / 10;

	if (num == 0) return;

	result = result * 10;
	
	imagen(num, result);
}










int main() {

	int num = 123456789, result = 0;

	imagen(num, result);

	cout << result << endl;

	system("PAUSE");
	return 0;
}