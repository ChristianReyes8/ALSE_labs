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

ostream& operator <<(ostream& stream, complejo& a){
	stream << a.real << " + " << a.imag << "j";
	return stream;
}

complejo operator +(complejo& a, complejo& b){
	complejo c;
	c.real = a.real +  b.real;
	c.imag = a.imag +  b.imag;
	return c;
}

complejo operator -(complejo& a, complejo& b){
    complejo c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

bool operator <(complejo& a, complejo& b){
    //cout << "Usando el comparador" << endl;
    return angulo(a) < angulo(b);
}

/**
 * @brief comp_prom Esta función calcula el complejo promedio.
 *
 * Esta función permite calcular el complejo que resulta ser el promedio
 * de todos los complejos pasados en un vector a. Se calcula como el promedio
 * de la parte real y el promedio de la imaginaria por aparte.
 * @param a El vector que contiene los complejos.
 * @return El complejo con el promedio.
 */
complejo comp_prom(vector<complejo>& a){
	complejo prom;
	prom.real = 0.;
	prom.imag = 0.;
	int m = a.size();
	for(int i=0; i< m; i++)
		prom.real += a.at(i);
		
	prom.real /= m;
	prom.imag /= m;
	return prom;
}

complejo com_prom_iterador(vector<complejo>& a){
	complejo prom;
	prom.real = 0.;
	prom.imag = 0.;
	vector<complejo>::iterator it;
	for(it = a.begin(); it < a.end(); it++){
		prom.real += (*it)
	
	prom.real /= a.size();
	prom.imag /= a.size();
	return prom;
}

void ordernar(vector<complejo>& a){
    bool cambios;
    complejo temp;
    do{
        cambios = false;
        for(int i = 0; i < a.size()-1; i++){
            if(!(a.at(i) < a.at(i+1))){
                cambios = true;
                temp = a.at(i);
                a.at(i) = a.at(i+1);
                a.at(i+1) = temp;
            }
        }
    }while (cambios);
}



int main(int argc, char** argv){
	
	if(argc != 2){
        cout << "El programa se usa así:" << endl;
        cout << "complejos path_to_file" << endl;
        cout << "Se debe indicar la ruta al archivo a leer" << endl;
        return 1;
    }

    string path;
    path = argv[1];
    ifstream archivo;
    archivo.open(path);

    cout << "Se abrirá el archivo: " << path << endl;

    complejo uncomp;
    float a,b;
    vector<complejo> vcomp;
    vector<float>   vnormas;
 

    if(archivo.is_open()){
        // Aquí va el codigo que se va a hacer para leer el archivo
        while(!archivo.eof()){
            getline(archivo, path);
            a = atof(path.c_str());
            getline(archivo, path);
            b = atof(path.c_str());
            uncomp.real = a;
            uncomp.imag = b;

            // Aquí adiciono el complejo al vector
            vcomp.push_back(uncomp);
        }

        // Ahora voy a calcular las normas
        int m = vcomp.size();
        for(int i=0; i < m ; i++){
            vnormas.push_back( norma( vcomp.at(i) ) );
            vangulos.push_back( angulo( vcomp.at(i) ) );
            cout << vnormas.at(i) << ", " << vangulos.at(i) << endl;
        }

        //y el promedio
        uncomp = com_prom( vcomp );
        cout << "El promedio es : "<< uncomp.real << " + " << uncomp.imag << "j" << endl;

        uncomp = com_prom_iterador( vcomp );
        cout << "El promedio es : "<< uncomp.real << " + " << uncomp.imag << "j" << endl;

        // ahora usando el operador sobrecargado
        cout << "El promedio es: " << uncomp << endl;

        // Ordenar el vector
        ordernar(vcomp);

        vnormas.clear();
        vangulos.clear();

        for(int i=0; i < m ; i++){
            vnormas.push_back( norma( vcomp.at(i) ) );
            vangulos.push_back( angulo( vcomp.at(i) ) );
            cout << vnormas.at(i) << ", " << vangulos.at(i) << endl;
        }


    }else{
        cout << "verifique el archivo a ser leído." << endl;
    }
	
	return 0;
}
