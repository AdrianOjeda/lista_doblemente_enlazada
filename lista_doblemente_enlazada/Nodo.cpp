#include "Nodo.h"
#include <string.h>

Nodo::Nodo() {
	alumno.edad = 0;
	*alumno.nombre = {};
}
Nodo::Nodo(Alumno alumno, Nodo* sig, Nodo* ant) {

	strcpy_s(this->alumno.nombre, alumno.nombre);
	this->alumno.edad = alumno.edad;
	this->sig = sig;
	this->ant = ant;

}
