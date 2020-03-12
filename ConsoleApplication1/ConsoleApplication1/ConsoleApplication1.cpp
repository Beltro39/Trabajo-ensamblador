/// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

	
#include <iostream>
#include <string>
using namespace std;

int main(int argc)
{



	// Informacion relevate del programa y de los creadores
	cout << "\n"
		<< " BIENVENIDO \n "
		<< "\n"
		<< "Asignatura: ARQUITECTURA DE COMPUTADORES 2019-2\n"
		<< "Creadores del programa: \n"
		<< "1. SEBASTIAN BELTRAN ARENAS \n"
		<< "2. DANIER STEVEN MUÑOZ BETANCUR \n"
		<< "3. YINIER ARTURO RAMIREZ BARAHONA \n"
		<< "______________________________________________________________________________________________________________________________________ \n"
		<< "Mediante este programa se podra realizar la operacion de atan(x/a) \n"
		<< "mediante la seria de Taylor propuesta en el quiz \n"
		<< "la cual se desarrollo con una mezcla entre el lenguaje c++ y ensamblador\n"
		<< "______________________________________________________________________________________________________________________________________ \n";


	int x;
	int a;
	int m;
	double resultado= 0.0;
	int var;
	double varD;
	double s;
	int n;
	double nPorDosMasUno= 0;


	cout << "Digite un numero x: ";
	cin >> x;

	cout << "\nDigite un numero a: ";
	cin >> a;

	cout << "\nDigite un numero m: ";
	cin >> m;

	_asm {
		//; TITLE Arco tangente por medio de una serie de Taylor
		//INCLUDE Irvine32.inc


		//.DATA
	//	var  DWORD ? ;
		//varD REAL4 ? ;
		
		//.CODE 
        //main PROC
         finit
	

	
	     cmp m, 0;              //if(m>0){Haga todo}
	     jle mIgualACero;
	
	     mov ecx, m;
         Sumatoria:
	     fild x;                //Se agrega x a la pila
	     fild a;                //Se agrega a a la pila
	     fdiv;                  //El valor del tope de la pila es x/a
	     fst s;                 // S= x/a 


	     MOV n, ecx;
	     MOV eax, n;            //eax= n
	     MOV ebx, 2;            //ebx= 2
	     IMUL ebx;              //eax= eax*ebx
         MOV ecx, eax;          //ecx= eax

	                            //Proceso para darle el valor a la variable nPorDosMasUno
	     ADD eax, 1;
	     MOV var, eax;
	     fild var;
	     fstp nPorDosMasUno;    //nPorDosMasUno= 2n+1
	  
	
         Potenciacion:
	       fmul s;
	     loop Potenciacion;
	                            //Tope de la pila= (x/a)**(2n+1)
	  

	     fdiv nPorDosMasUno;    //Tope de la pila [(x/a)**(2n+1)]/(2n+1)
	 
	

	                            //Proceso para saber si n es par o impar
	     xor edx, edx;
	     MOV eax, n;
	     MOV ecx, 2;            //Se hace mirando si el residuo de la
	     div ecx;               //division por 2, es uno o cero
	
	     cmp edx, 0;
	     jle par;               //Si n es par, salta a la etiqueta par
	     mov eax, -1;           //Si n es impar, se multiplica todo por -1, de lo contrario solo se multiplica por 1

         par:
	     MOV var, eax;
	     fild var;
	     fstp varD;
	     fmul varD;              //Tope de la pila= [[(x/a)**(2n+1)]/(2n+1)]*(-1)**n
 

	     fadd resultado;
         fstp resultado;         //Resultado guardara la sumatoria
	     fstp varD;
	     MOV ecx, n;
	     loop Sumatoria;

         mIgualACero:
	     fild x;                 //Se agrega x a la pila
	     fild a;                 //Se agrega a a la pila
	     fdiv;                   //El valor del tope de la pila es x/a

	     fadd resultado;             
	     fstp resultado;
    
	   // main ENDP
       // END main 
	}
	cout << "\n";
	cout << resultado;
	cout << "\n";

	cout << "\n";
	//cout << nPorDosMasUno;
	cout << "\n";

	
	
	getchar();
	system("pause");
	return 0;
}
