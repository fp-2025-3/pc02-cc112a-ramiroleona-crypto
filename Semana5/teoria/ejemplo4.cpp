#include <iostream>
using namespace std;

//ESTRUCTURA AUTORREFERENCIADA
struct Producto {
    int codigo;
    float precio;
    Producto *sig;
};

int main () {

    Producto *cabeza = nullptr;

    //insertar producto al inicio

    for (int i = 0; i < 2; i++){
        Producto *nuevo = new Producto;
        cout << "Ingrese codigo: "; cin >> nuevo->codigo;
        cout << "Ingrese precio: "; cin >> nuevo->precio;
        nuevo->sig = cabeza;
        cabeza = nuevo;
    }

    //mostrar los productos
    Producto *aux = cabeza;
    while (aux != nullptr){
        cout << aux->codigo << "   " << aux->precio << endl;
        cout << "-------------------------";
        aux = aux->sig;
    }

    //liberar memoria
    Producto *temp = cabeza;  
    while (cabeza != nullptr){
        Producto *temp = cabeza;
        cabeza = cabeza->sig;
        delete temp;
        temp = nullptr;
    }

    return 0;
}