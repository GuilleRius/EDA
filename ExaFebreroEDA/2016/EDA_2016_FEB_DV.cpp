/*El ISBN de un libro consta actualmente de 13 dgitos d1 d2 : : : d13.Al dgito d13
se le denomina dgito de control y se calcula a partir de los anteriores de la siguiente forma :
primero se calcula la suma de multiplicar cada dgito de una posicion par por 3 y cada dgito de
una posicion impar por 1. Los dgitos se numeran desde el 1 empezando por el mas signicativo :
d1  1 + d2  3 + d3  1 + d4  3 + d5  1 + d6  3 + d7  1 + d8  3 + d9  1 + d10  3 + d11  1 + d12  3
El dgito d13 sera aquel que sumado con el resultado de dicha suma de un multiplo de 10. Por
ejemplo, el dgito de control del numero 336772900480 es 9 porque la suma anterior da como
resultado 81 y 81 + 9 = 90, que es multiplo de 10.
Dise~nar un algoritmo recursivo eciente que ayude a calcular el dgito de control de un ISBN con
cualquier numero de dgitos.Igual que en el ejemplo, los dgitos anteriores vienen dados como un
numero entero.Por ejemplo, si el numero dado es 2561, la suma sera 21 + 53 + 61 + 13 = 26
y por tanto el resultado sera 4. Indicar y justificar la complejidad del algoritmo.*/

#include<iostream>

using namespace std;

long int ISBN(long long int &num, long long int digitos, long long int &suma) {

	if (digitos == 0) return (10 - suma % 10);

	else if (digitos % 2 == 0) suma += (num % 10) * 3;

	else suma += (num % 10);

	num = num / 10;

	ISBN(num, digitos - 1, suma);
}


int main() {

	long long int num = 336772900480, digitos = 12, suma = 0;

	cout << ISBN(num, digitos, suma) << endl;

	system("Pause");
	return 0;
}