    #include <iostream>
	#include <math.h>
	using namespace std;
	
	/*  Aquí voy a definir una estructura para manejar los
	 * números complejos
	 */
	struct complejo{
		float real;
		float imag;
	};

	float norma(complejo& a){
		return sqrt(a.real*a.real+a.imag*a.imag);
	}
	
	float angulo(complejo& a){
		return atan2( a.imag, a.real );
	}

	int main(int argc, char** argv){
		
		float mag, ang;
				
		cout << "Hello world!" << endl;
		cout << "Se pasaron " << argc << " parámetros." << endl;
		cout << "Estas son cadenas de texto!!" << endl;
		
		for(int i=0; i < argc; i++){
			cout << argv[i] << endl;
		}
		
		//	Conversi\'on de texto a n\'umero
		cout << "ahora se pasan a números:" << endl;
		
		complejo a;
		if(argc == 3){
			a.real = atof(argv[1]);
			a.imag = atof(argv[2]);
			cout << "La suma de los dos parámetros es: " << a.real + a.imag << end;
		}
		
		mag = norma( a );
		ang = angulo ( a );
		cout << "La norma de: " << a.real << " + " << a. imag << "j es " << mag << " y su ángulo es: " << ang << " rad." << endl;
		
		
		return 0;
	}
