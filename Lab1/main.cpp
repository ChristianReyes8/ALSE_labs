    #include <iostream>
	#include <math.h>
	using namespace std;
	
	 
	int main(int argc, char** argv){
		
		float real, imaginario, mag;
		real = imaginario = mag = 0.;
		
		cout << "Hello world!" << endl;
		cout << "Se pasaron " << argc << " parámetros." << endl;
		cout << "Estas son cadenas de texto!!" << endl;
		
		for(int i=0; i < argc; i++){
			cout << argv[i] << endl;
		}
		
		//	Conversi\'on de texto a n\'umero
		cout << "ahora se pasan a números:" << endl;
		
		if(argc == 3){
			real = atof(argv[1]);
			imaginario = atof(argv[2]);
			cout << "La suma de los dos parámetros es: " << real + imaginario << end;
		}
		
		mag = sqrt( real * real + imaginario * imaginario );
		cout << "La norma de: " << real << " + " << imaginario << "j es " << mag << endl;
		
		
		return 0;
	}
