#include <iostream>
using namespace std;

/*
Se tiene una frase almacenada en un arreglo de caracteres. Las palabras están separadas por uno o más espacios.

char frase[] = "aprender punteros exige mucha logica y practica";
Implementar un programa que:

Identifique cada palabra dentro del arreglo frase.
Guarde punteros al inicio de cada palabra, sin copiar caracteres.
Use un arreglo de punteros a char (char* palabras[]).
Ordene las palabras alfabéticamente, intercambiando solo punteros.
Imprima las palabras ordenadas leyendo desde los punteros.
La frase original NO debe modificarse.

Considerando como datos de entrada:

char frase[200] = "aprender punteros exige mucha logica y practica";      // arreglo base de caracteres
char* palabras[50];  // arreglo de punteros a palabras
Implemente las siguientes funciones:

int separar_palabras(char* frase, char* palabras[]);
int comparar(const char* a, const char* b);
void ordenar(char* palabras[], int n);
void imprimir(char* palabras[], int n);
Salida esperada:

aprender
exige
logica
mucha
practica
punteros
y
Observaciones: Algunas desventajas de este enfoque

No es posible conservar palabras fuera del alcance de frase.
No se pueden crear palabras nuevas ni devolverlas desde una función.
El tamaño de los arreglos es fijo.
*/

int separar_palabras(char* frase, char* palabras[]);
int comparar(const char* a, const char* b);
void ordenar(char* palabras[], int n);
void imprimir(char* palabras[], int n);

int main(){

    char frase[] = "aprender punteros exige mucha logica y practica";
    char *palabras[50]; 

    /*
    1. guardar un puntero al inicio de cada una sin copiar caracteres
    2. ordenar las palabras alfabeticamente
    3. imprimir las palabras ordenadas leyendo desde los punteros
    */

    cout << "Frase original:\n";
    cout << endl;
    int cantidad_palabras = separar_palabras(frase, palabras);
    imprimir (palabras, cantidad_palabras);
    ordenar(palabras, cantidad_palabras);
    cout <<endl;
    cout << "Frase con palabras ordenadas alfabeticamente:\n";
    cout << endl;
    imprimir (palabras, cantidad_palabras);

    return 0;
}

//funcion para separar palabras
//a modo de practica, no trabajare con strtok, por tratarse de una frase que no incluye otros signos de puntuacion
int separar_palabras(char* frase, char* palabras[]){
    int i = 0;
    char *p = frase;
    
    while (*p != '\0'){
        //cantidad_palabras tambien funciona como indice para el arreglo de punteros a char palabras
        if ((p == frase || *(p-1) == ' ') && *p != ' '){
            palabras[i] = p;
            i++;
        }
        p++;
    }

    return i;
    
}

//funcion para comparar y retornar orden alfabetico
int comparar(const char* a, const char* b){

    while (*a == *b && *a != '\0' && *b != '\0' && *a != ' ' && *b != ' '){
        a++;
        b++;
    }

    return *a - *b;
}

//usaremos burbuja para ordenar
void ordenar(char* palabras[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (comparar(palabras[j], palabras[j+1]) > 0){
                //hacemos los intercambios apropiados, que no seran alterados por mas que hayan mayusculas o minusculas
                swap(palabras[j], palabras[j+1]);
            }
        }
    }
}

void imprimir(char* palabras[], int n){

    for (int i = 0; i < n; i++){
        char *p = palabras[i];
        while (*p != '\0' && *p != ' '){
            cout << *p;
            p++;
        }
        cout << endl;
    }
}