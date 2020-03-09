/// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc)
{
	// Your code here!
	int x;
	int a;
	int m;
	int radian = 180;
	double s[1];
	cout << "Digite un numero x: ";
	cin >> x;

	cout << "\nDigite un numero a: ";
	cin >> a;

	cout << "\nDigite un numero m: ";
	cin >> m;

	_asm {
		finit

		fild x;
		fild a;
		fdiv;
		fstp s[0];


		/*
		move ebx, x
		filds ebx;
		move ebx, a
		filds ebx;
		fdiv 
		fsts s;
		*/
		
	}
	cout << "\n";
	cout << s[0];
	cout << "\n";

	/*
	cout << "\n";
	cout << x;
	cout << "\n";
	cout << a;
	cout << "\n";
	cout << m;
	cout << "\n";
	*/

	
	getchar();
	system("pause");
	return 0;
}
