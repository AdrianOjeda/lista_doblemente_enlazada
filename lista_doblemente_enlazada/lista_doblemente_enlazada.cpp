
#include "Lista.h"
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
    int opcion,  posicion;
    char resp;


    Lista* list = new Lista;
    Alumno alumno;
    cout << "*** Lista doblemente enlazada *** " << endl << endl;
    do {
        cout << "Eliga una opcion: " << endl << "1: Insertar Alumno al inicio" << endl << "2: Insertar Alumno al final" << endl << "3: Insertar Alumno en posicion determinada" << endl << "4: Eliminar Alumno" << endl << "5: Eliminar todo" << endl << "6: Buscar Alumno" << endl << "7: Inicializa lista" << endl << "8: Vacia" << endl << "9: Mostrar el primer alumno de la lista" << endl << "10: Mostrar el ultimo alumno de la lista" << endl << "11: Mostrar el tamano de la lista" << endl << "12: Siguiente" << endl << "13: Anterior" << endl << "14: Mostrar todo" << endl;

        cin >> opcion;
        switch (opcion) {
        case 1: {
            cout << "*** Insertar alumno al inicio ***" << endl;
            cout << "Ingrese la edad del alumno: ";
            cin >> alumno.edad;
            cout << "Ingrese el nombre del alumno: ";
            cin.ignore();
            cin.getline(alumno.nombre, 30);
            list->insertarInicio(alumno);
            break;
        }case 2: {
            cout << "*** Insertar alumno al final ***" << endl;

            if (list->vacia() == false) {
                cout << "Ingrese la edad del alumno: ";
                cin >> alumno.edad;
                cout << "Ingrese el nombre del alumno: ";
                cin.ignore();
                cin.getline(alumno.nombre, 30);
                list->insertarFinal(alumno);
            }


            break;
        }case 3: {
            cout << "*** Insertar Alumno en posicion ***" << endl;
            if (list->vacia() == false) {
                cout << "Escriba la posicion en la que quiere insertar el elemento: ";
                cin >> posicion;
                if (posicion > 0 && posicion <= list->tamanoLista()) {
                    cout << "Ingrese la edad del alumno que desea insertar: ";
                    cin >> alumno.edad;
                    cin.ignore();
                    cout << "Ingrese el nombre del alumno que desea insertar: ";
                    cin.getline(alumno.nombre, 30);
                    list->insertarPosicion(posicion, alumno);
                }
                else {
                    cout << "La posicion deseada no es valida" << endl;
                }
            }

            break;
        }case 4: {
            cout << "*** Eliminar alumno ***" << endl;

            if (list->vacia() == false) {
                cout << "Ingrese la edad del alumno que desea eliminar: ";
                cin >> alumno.edad;
                cin.ignore();
                cout << "Ingrese el nombre del alumno que desea eliminar: ";
                cin.getline(alumno.nombre, 30);
                list->eliminar(alumno);
            }
            break;
        }case 5: {

            cout << "*** Eliminando todo ***" << endl;
            cout << endl;
            if (list->vacia() == false) {
                list->eliminarTodo();
            }


            break;
        }case 6: {
            cout << "*** Buscar Alumno ***" << endl;
            if (list->vacia() == false) {
                cout << "Ingrese la edad del alumno que quiere buscar: ";
                cin >> alumno.edad;
                cin.ignore();
                cout << "Ingrese el nombre del alumno que desea buscar: ";
                cin.getline(alumno.nombre, 30);
                cout << "El alumno esta en la posicion: " << list->buscar(alumno) << endl;


            }
            break;
        }case 7: {
            cout << "*** Inicializar lista***" << endl;
            cout << "...";
            Lista* list = new Lista;
            cout << " Lista inicializada!" << endl;
            break;
        }case 8: {
            cout << "*** Vacia ***" << endl;
            if (list->vacia() == false) {
                cout << "La lista no esta vacia!" << endl;

            }
            break;
        }case 9: {
            cout << "*** Mostrando el primer alumno de la lista ***" << endl;
            if (list->vacia() == false) {
                list->primerElemento();

            }
            break;
        }case 10: {
            cout << "*** Mostrando el ultimo alumno de la lista ***" << endl;
            if (list->vacia() == false) {
                list->ultimoElemento();

            }
            break;
        }case 11: {
            cout << "*** Tamano de la lista ***" << endl;
            if (list->vacia() == false) {
                cout << endl << "El tamano de la lista es de: " << list->tamanoLista() << endl;

            }
            break;
        }case 12: {
            cout << "*** Siguiente ***" << endl;
            if (list->vacia() == false) {
                cout << "Ingrese la edad del alumno que desea buscar: ";
                cin >> alumno.edad;
                cin.ignore();
                cout << "Ingrese el nombre del alumno que desea buscar: ";
                cin.getline(alumno.nombre, 30);
                posicion = list->buscar(alumno);
                if (posicion > 0 && posicion <= list->tamanoLista()) {
                    list->siguiente(alumno);
                }
                else {
                    cout << "El alumno ingresado no se encuentra en la lista, ingrese un alumno valido!" << endl;

                }

            }

            break;
        }case 13: {
            cout << "*** Anterior ***" << endl;
            if (list->vacia() == false) {
                cout << "Ingrese la edad del alumno que quiere buscar: ";
                cin >> alumno.edad;
                cin.ignore();
                cout << "Ingrese el nombre del alumno que desea buscar: ";
                cin.getline(alumno.nombre, 30);
                posicion = list->buscar(alumno);
                if (posicion > 0 && posicion <= list->tamanoLista()) {

                    list->anterior(alumno);
                }
                else {
                    cout << "El alumno ingresado no se encuentra en la lista, ingrese un alumno valido!" << endl;

                }

            }
            break;
        }case 14: {
            list->mostrar();
            break;
        }default: {
            cout << "Ingrese una opcion valida!!" << endl;
            break;
        }


        }

        cout << "Desea continuar? y/n: ";
        cin >> resp;
    } while (resp == 'y' || resp == 'Y');
    delete list;

}