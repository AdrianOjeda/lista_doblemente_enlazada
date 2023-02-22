#pragma once
#include "Nodo.h"
class Lista
{
public:
	Nodo* header;
	Nodo* tail;
	Alumno alumno;
	Lista();
	Lista(Nodo*, Nodo*);
	void insertarInicio(Alumno);
	void mostrar();
	void eliminarTodo();
	void eliminar(Alumno);
	void insertarFinal(Alumno);
	bool vacia();
	int tamanoLista();
	void insertarPosicion(int, Alumno);
	int buscar(Alumno);
	void primerElemento();
	void ultimoElemento();
	void anterior(Alumno);
	void siguiente(Alumno);
};

