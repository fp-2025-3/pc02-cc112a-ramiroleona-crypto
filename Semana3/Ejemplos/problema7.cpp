#include <iostream>
using namespace std;

//funcion para recorrer una cadena con punteros
void Imprimir (const char *p){
    while (*p != '\0'){
        cout << *p;
        p++;
    }
}

int main () {

    //cuidado, el nombre de un arreglo es un puntero constante 
    //a su primer elemento 
    char nombre[] = "Ramiro";
    char * p = nombre;
    Imprimir (p);

    return 0;
}