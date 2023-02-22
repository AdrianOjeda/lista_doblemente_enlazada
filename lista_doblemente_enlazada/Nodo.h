#pragma once
#include "Alumno.h"

class Nodo
{
public:
	Alumno alumno;
	Nodo* sig;
	Nodo* ant;
	Nodo();
	Nodo(Alumno, Nodo*, Nodo*);
};

