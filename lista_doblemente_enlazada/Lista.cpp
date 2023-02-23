#include "Lista.h"
#include <iostream>
using namespace std;


Lista::Lista() {
	header = nullptr;
	tail = nullptr;

}
Lista::Lista(Nodo* ptr, Nodo* ptrtail) {
	header = ptr;
	tail = ptrtail;

}


void Lista::insertarInicio(Alumno alumno) {
	Nodo* temp = new Nodo(alumno, nullptr, nullptr);
	if (!header){
		header= temp;
		tail = temp;
		cout << "Alumno ingresado con exito!" << endl;
	}
	else {
		//header = temp;
		temp->sig = header;
		header->ant = temp;
		header = temp;
	}
}

void Lista::mostrar() {
	Nodo* aux = header;

	if (header) {
		while (aux != tail->sig) {
			cout << "Nombre: " << aux->alumno.nombre << " | Edad: " << aux->alumno.edad << endl;
			aux = aux->sig;
		}
		cout << endl;
	}
	else {
		cout << endl << "Lista vacia" << endl;
	}

}

void Lista::eliminarTodo() {

	Nodo* aux = header;
	while (aux != nullptr) {
		Nodo* temp = aux;
		aux = aux->sig;
		delete temp;
	}
	header = nullptr;
	tail = nullptr;
	delete aux;
	cout << "Lista eliminada con exito!" << endl;
}

void Lista::insertarFinal(Alumno alumno) {
	Nodo* temp = new Nodo(alumno, nullptr, nullptr);
	Nodo* ultimo = header;
	while (ultimo != tail) {
		ultimo = ultimo->sig;
	}
	temp->ant = tail;
	tail->sig = temp;
	tail = temp;
	tail->sig = nullptr;
	cout << "Alumno ingresado con exito!" << endl;

}
void Lista::eliminar(Alumno alumno) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	if (header != nullptr) {
		while (aux && bandera) {
			if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
				bandera = false;
			}
			else {
				auxAnterior = aux;
				aux = aux->sig;

			}
		}
		if (aux == nullptr) {
			cout << "No se encontro el Alumno" << endl;

		}
		else if (aux == header) {
			header = header->sig;
			header->ant = nullptr;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;

		}
		else if (aux->sig == nullptr) {
			tail = tail->ant;
			tail->sig = nullptr;
			//aux->ant->sig=nullptr;

			//auxAnterior->sig = nullptr;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;

		}
		else {

			aux->ant->sig = aux->sig;
			aux->sig->ant = aux->ant;
			//auxAnterior->sig = aux->sig;
			delete aux;
			cout << "Alumno eliminado con exito!" << endl;
		}

	}
}

bool Lista::vacia() {

	if (header) {
		cout << "hola" << endl;
		return false;
	}
	else {
		cout << endl << "Lista vacia" << endl;
		return true;
	}

}

int Lista::tamanoLista() {
	int contador = 0;
	Nodo* aux = header;
	while (aux != nullptr) {
		aux = aux->sig;
		contador++;

	}
	return contador;
}

void Lista::insertarPosicion(int posicion, Alumno alumno) {
	int contador = 0;
	Nodo* aux = header;
	//Nodo* auxAnterior = nullptr;
	Nodo* temp = new Nodo(alumno, nullptr, nullptr);
	if (posicion == 1) {
		temp->sig = header;
		header->ant = temp;
		header = temp;

		cout << "Alumno ingresado con exito!" << endl;
	}
	else {
		while (contador < posicion - 1) {
			
			aux = aux->sig;
			contador++;

		}
		temp->sig = aux;
		temp->ant = aux->ant;
		aux->ant->sig = temp;
		aux->ant = temp;
		cout << "Alumno ingresado con exito!" << endl;
	}

}

int Lista::buscar(Alumno alumno) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	int contador = 1;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
			contador++;
		}
	}
	return contador;
}
void Lista::primerElemento() {
	
	cout << "Nombre: " << header->alumno.nombre << " | edad: " << header->alumno.edad << endl;

}
void Lista::ultimoElemento() {
	
	cout << "Nombre: " << tail->alumno.nombre << " | edad: " << tail->alumno.edad << endl;
	

}
void Lista::siguiente(Alumno alumno) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
		}
	}
	if (aux->sig == nullptr) {
		cout << "El alumno ingresado ya es el ultimo de la lista!" << endl;
	}
	else {
		cout << "El Alumno que sigue de " << alumno.nombre << " es: " << endl;
		cout << "Nombre: " << aux->sig->alumno.nombre << " | edad: " << aux->sig->alumno.edad << endl;
	}
}

void Lista::anterior(Alumno alumno) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	while (aux && bandera) {
		if (alumno.edad == aux->alumno.edad && strcmp(alumno.nombre, aux->alumno.nombre) == 0) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;

		}
	}
	if (aux == header) {
		cout << "El alumno ingresado es el primero de la lista!" << endl;
	}
	else {
		cout << "El Alumno que esta antes de " << alumno.nombre << " es: " << endl;
		cout << "Nombre: " << auxAnterior->alumno.nombre << " | edad: " << auxAnterior->alumno.edad << endl;
	}

}
