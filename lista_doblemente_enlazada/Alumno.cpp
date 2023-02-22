#include "Alumno.h"
#include <string.h>

Alumno::Alumno() {

	edad = 0;
	*nombre = {};
}

Alumno::Alumno(int edad, char* nombre) {
	this->edad = edad;
	strcpy_s(this->nombre, nombre);
}
