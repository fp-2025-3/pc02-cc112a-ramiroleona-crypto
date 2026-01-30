#include <iostream>
using namespace std;

/*
En muchos sistemas (libros, diccionarios, compiladores, buscadores) se construyen 
índices que permiten acceder rápidamente a información sin duplicar los datos originales.

Considere la siguiente frase almacenada en un arreglo fijo de caracteres

char texto[] = "los punteros no se copian se referencian y se ordenan";
Implementar un programa que:

Identifique todas las palabras del arreglo texto.

Construya un índice léxico, es decir:

Un arreglo de punteros a char que apunten al inicio de cada palabra.
Ordene el índice alfabéticamente.

Imprima el índice mostrando:

La palabra
La posición (índice) donde comienza dentro del arreglo texto
El texto original no debe modificarse ni copiarse.

considerando como datos de entrada

char texto[300] = "los punteros no se copian se referencian y se ordenan";      // arreglo base
char* indice[60];    // arreglo de punteros a palabras
Implemente las siguientes funciones:

int construir_indice(char* texto, char* indice[]);
int comparar(const char* a, const char* b);
void ordenar_indice(char* indice[], int n);
void imprimir_indice(char* texto, char* indice[], int n);
Salida esperada:

copian        (posicion 19)
los           (posicion 0)
no            (posicion 13)
ordenan       (posicion 45)
punteros      (posicion 4)
referencian   (posicion 29)
se            (posicion 16)
se            (posicion 26)
y             (posicion 42)
Cada línea muestra:

la palabra (leída desde el puntero)
la posición donde inicia dentro del arreglo texto
*/

int construir_indice(char* texto, char* indice[]);
int comparar(const char* a, const char* b);
void ordenar_indice(char* indice[], int n);
void imprimir_indice(char* texto, char* indice[], int n);

int main(){

    char texto[300] = "los punteros no se copian se referencian y se ordenan";      // arreglo base
    char* indice[60];    // arreglo de punteros a palabras

    int cantidad = construir_indice(texto, indice);
    ordenar_indice(indice, cantidad);
    imprimir_indice(texto, indice, cantidad);

    return 0;
}

int construir_indice(char* texto, char* indice[]){
    int i = 0;
    char *p = texto;
    
    while (*p != '\0'){
        if ((p == texto || *(p-1) == ' ') && *p != ' '){
            indice[i] = p;
            i++;
        }
        p++;
    }

    return i;
}

int comparar(const char* a, const char* b){

    while (*a == *b && *a != '\0' && *b != '\0' && *a != ' ' && *b != ' '){
        a++;
        b++;
    }

    return *a - *b;
}

void ordenar_indice(char* indice[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (comparar(indice[j], indice[j+1]) > 0){
                swap(indice[j], indice[j+1]);
            }
        }
    }
}

void imprimir_indice(char* texto, char* indice[], int n){
    for (int i = 0; i < n; i++){
        char *p = indice[i];
        char *localizacion = texto;
        int indice_texto;
        for (int j = 0; j<300; j++){
            if (localizacion == p){
                indice_texto = j;
                break;
            }
            localizacion++;
        }
        while (*p != '\0' && *p != ' '){
            cout << *p;
            p++;
        }
        cout << "               (posicion" << indice_texto << ")" << endl;
    }
}