#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Pentagono.h"

using namespace std;

int main(){
    Circulo a = Circulo( 5. );
    cout << a << endl;
    a.setRadio( 7. );
    cout << a << endl;
	
	Cuadrado c = Cuadrado( 9.5 );
	cout << c << endl;
    c.setLado( 17. );
    cout << c << endl;
	
	Triangulo t = Triangulo( 6.5, 7.9 );
	cout << t << endl;
	t.setBase( 88. );
	t.setAltura( 10. );
	cout << t << endl;
	
	Pentagono p = Pentagono( 9.5 );
	cout << p << endl;
    p.setLado( 17. );
    cout << p << endl;
	
    cout << "Hello World!" << endl;
    return 0;
}
