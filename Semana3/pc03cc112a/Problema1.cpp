#include <iostream>
using namespace std;

/*
Considerando como datos de entrada una cadena de caracteres que contiene numeros enteros
ordenadas en forma ascendente, separados por coma y/o espacio y un entero k.
Implemente un algoritmo O(n) que utilice punteros para procesar la cadena y determine si
existe un par de numeros dentro de la cadena cuya suma sea igual a k.
*/

bool ExistenNumeros (char *texto, int valor);

int main () {

    char texto[] = "1, 2, 4, 7, 11";

    /*lo conveniente aqui seria utilizar el token de la libreria cstring; sin embargo, para fines practicos,
    restringuiremos manualmente los valores y realizaremos las asignaciones.
    */

    int k; 
    cout << "Ingrese un valor para k: "; cin >> k;
    cout << endl;

    bool Existen = ExistenNumeros (texto, k);

    if (Existen){
        cout << "SI ";
    }

    if (!Existen) {
        cout << "NO ";
    }
    cout << "existen 2 numeros con suma " << k;

    return 0;
}

bool ExistenNumeros (char *texto, int valor){

    //requerimos un algoritmo O(n), donde n sera la cantidad de datos numericos extraidos de la cadena
    //digamos que nuestro tope es de 40 numeros 
    int numeros[40];
    char *p = texto;
    int cantidad_numeros = 0;

    //aislamos los numeros
    /*
    la estrategia para encontrar un valor sera trabajar con complementos. Ya que la secuencia es ascendente, esta claro que 
    k - numeros[i] deberia de estar en la secuencia, de modo que podemos buscar el valor y asi descartar valores ya utilizados.
    Si tenemos el total de numeros, que estan ordenados, podemos ubicar un puntero al final y otro al inicio, e ir descartando.
    */
    while (*p != '\0') {
        //avance sucesivo para dividir por tokens y luego convertir los numeros
        while (*p == ' ' || *p == ',') {
            p++;
        }

        if (*p == '\0') break;

        int num = 0;

        while (*p >= '0' && *p <= '9') {
            num = num * 10 + (*p - '0');
            p++;
        }
        numeros[cantidad_numeros] = num;
        cantidad_numeros++;
    }

    //ubicamos punteros al inicio y al final del arreglo almacenado
    int *p1 = numeros;
    int *p2 = numeros + cantidad_numeros - 1;
    
    while (p1 < p2){
        if (*p1 + *p2 == valor){
            return true;
        }
        //desplazamos el puntero final a la izquierda
        if (*p1 + *p2 > valor){
            p2--;
        }
        //desplazamos el puntero inicial a la derecha
        else {
            p1++;
        }
    }

    return false;
}