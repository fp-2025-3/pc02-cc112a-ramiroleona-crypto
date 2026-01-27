#include <iostream>
#include <cstring>
using namespace std;

/*
Dado una lista de nombres
char nombres[][20] = {
    "Leslye",
    "Americo",
    "Xingbeck",
    "William",
    "Julio",
    "Darwin",
    "Kevin"
}
    1. Ordenar la lista en orden alfabetico ascendente
    2. No usar []
        use aritmetica de punteros
*/

void ordenar (const char ** nombres, int n){
    for ()
}

void ordenar (char (*nombres)[20], int n){

    //burbuja
    char temp[30];
    for (char(*i)[20] = nombres; i < nombres + n - 1; i++){
        for (char(*j)[20] = i + 1; j < nombres + n; j++){
            if (strcmp(*i, *j) > 0){
                strcpy(temp, *i);
                strcpy(*i, *j);
                strcpy(*j, temp);
            }
        }
    }
}

void imprimir (char (*nombres)[20], int n){
    for (char(*i)[20] = nombres; i < nombres + n; i++){
        cout << *i << endl;
    }
}

int main () {

    char nombres[][20] = {
        "Leslye",
        "Americo",
        "Xingbeck",
        "William",
        "Julio",
        "Darwin",
        "Kevin"
    };

    int n = sizeof(nombres)/sizeof(nombres[0]);

    cout << "Arreglo original:" << endl;
    imprimir (nombres, n);
    ordenar (nombres, n);
    cout << "Arreglo ordenado: " << endl;
    imprimir (nombres, n);

    return 0;
}

/*
RESOLVER EL MISMO EJERCICIO PERO USANDO UN ARREGLO DE PUNTEROS TIPO const char *nombres[]
*/