/**
 * Project Untitled
 */


#include "Pentagono.h"
#include <iostream>


using namespace std;
/**
 * Pentagono implementation
 */


/**
 * @param l
 * @param x
 * @param y
 */
Pentagono::Pentagono(float l, float x, float y ) {
	_lado = l;
	_xc = x;
	_yc = y;
}

/**
 * @return float
 */
float Pentagono::area() {
    return NaN;
}

/**
 * @return float
 */
float Pentagono::perimetro() {
    return NaN;
}

/**
 * @param stream
 * @return ostream&
 */
ostream& operator<<(ostream& stream, Pentagono& p) {
	stream << "Soy un pentágono que no sabe calcular su área ni su perímetro.";
    return stream;
}

Pentagono::Pentagono() {

}
