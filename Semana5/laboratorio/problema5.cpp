#include <iostream>
using namespace std;

/*
En un laboratorio de Ciencia de la Computación se está desarrollando un prototipo de sistema 
de sistema distribuido para simular la gestión de procesos que se ejecutan en diferentes nodos 
de una red.

Cada proceso tiene la siguiente información:

ID (identificador único entero)

Nombre del proceso

Consumo de memoria (en MB)

Para modelar dinámicamente la creación y eliminación de procesos en el sistema, se solicita 
implementar una lista enlazada simple utilizando memoria dinámica

a) Definir una estructura Proceso que representa un nodo de la lista enlazada

b) Definir una estructura ListaProcesos que contenga un puntero a la cabeza de la lista.

c) Implementar las siguientes operaciones

Inicializar la lista en estado vacío

Insertar al menos 3 elementos al inicio de la lista.

Insertar al menos 2 elementos al final de la lista

Mostrar todos los procesos almacenados en la lista

Buscar un proceso por su ID e indicar si fue encontrado o no

Eliminar un proceso dado su ID, considerando

Eliminación de la cabeza

Eliminación en posición intermedia

Eliminación al final

Caso donde el proceso no existe

Contar y mostrar el número de procesos en el sistema

Insertar un nuevo proceso manteniendo la lista ordenada de forma ascendente según el consumo de 
memoria

Liberar toda la memoria utilizada antes de finalizar el programa.

Con el objetivo de entender los principios fundamentales de POO como:

Abstracción: mostrar solo lo esencial y ocultar detalles de implementación

Encapsulación: agrupar datos y funciones que lo manipulan

Responsabilidad única (SRP): cada módulo debe encargarse de una sola cosa

Realice la implementación utilizando funciones como mostrar, buscar, eliminar, etc.
*/

struct Proceso {
    int id;
    string nombre;
    int consumoMemoria;
    Proceso* siguiente;
};

struct ListaProcesos {
    Proceso* cabeza;
};

void InicializarLista(ListaProcesos& lista) {
    lista.cabeza = nullptr;
}

void MostrarProcesos(ListaProcesos& lista) {
    Proceso* actual = lista.cabeza;
    while (actual != nullptr) {
        cout << "ID: " << actual->id << ", Nombre: " << actual->nombre 
             << ", Consumo de Memoria: " << actual->consumoMemoria << " MB" << endl;
        actual = actual->siguiente;
    }
}

bool BuscarProceso(ListaProcesos& lista, int id) {
    Proceso* actual = lista.cabeza;
    while (actual != nullptr) {
        if (actual->id == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void EliminarProceso(ListaProcesos& lista, int id) {
    Proceso* actual = lista.cabeza;
    Proceso* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->id == id) {
            if (anterior == nullptr) { // Eliminación de la cabeza
                lista.cabeza = actual->siguiente;
            } else { // Eliminación en posición intermedia o al final
                anterior->siguiente = actual->siguiente;
            }
            delete actual; // Liberar memoria del proceso eliminado
            cout << "Proceso con ID " << id << " eliminado." << endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Proceso con ID " << id << " no encontrado." << endl;
}

int ContarProcesos(ListaProcesos& lista) {
    int contador = 0;
    Proceso* actual = lista.cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void InsertarProcesoOrdenado(ListaProcesos& lista, int id, string nombre, int consumoMemoria) {
    Proceso* nuevoProceso = new Proceso{id, nombre, consumoMemoria, nullptr};

    if (lista.cabeza == nullptr || lista.cabeza->consumoMemoria >= nuevoProceso->consumoMemoria) {
        nuevoProceso->siguiente = lista.cabeza;
        lista.cabeza = nuevoProceso;
    } else {
        Proceso* actual = lista.cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->consumoMemoria < nuevoProceso->consumoMemoria) {
            actual = actual->siguiente;
        }
        nuevoProceso->siguiente = actual->siguiente;
        actual->siguiente = nuevoProceso;
    }
}

void LiberarMemoria(ListaProcesos& lista) {
    Proceso* actual = lista.cabeza;
    while (actual != nullptr) {
        Proceso* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    lista.cabeza = nullptr;
}

int main () {

    ListaProcesos lista;
    InicializarLista(lista);



    return 0; 
}