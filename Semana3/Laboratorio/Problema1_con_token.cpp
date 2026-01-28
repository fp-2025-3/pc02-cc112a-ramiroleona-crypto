#include <iostream>
#include <cstring>
using namespace std;

/*
Categoría: Ejercicio 01

Implementar un programa que:

    Identifique todas las palabras en un arreglo char texto[].

    Almacene punteros al al de incay cada palabra en un arreglo char* palabras[].

    Clasifique las palabras en dos grupos:
        cortasChuaboras (longitud ≤ 3)
        Palabras largas (longitud > 3)

    Imprima abos gruposs ordenas alfabéticamente.

El original texto no hay debese.
*/

//funciones a implementar
int separar_palabras(char* texto, char* palabras[]);
int longitud_palabra(const char* p);
void clasificar(char* palabras[], int n,
                char* cortas[], int& ncortas,
                char* largas[], int& nlargas);
int comparar_palabras(const char* a, const char* b);
void ordenar(char* v[], int n);
void imprimir_grupo(const char* titulo, char* v[], int n);
void intercambio (char **a, char **b);
//char *strtok (char *str, const char *, delimiters);

int main (){

    //datos de entrada:
    char* palabras[60];
    char* cortas[60];
    char* largas[60];

    char frase[] = "Programar en C++ requiere logica C++ exige disciplina";

    int cantidad_palabras = separar_palabras(frase, palabras);
    int ncortas = 0;
    int nlargas = 0;

    clasificar (palabras, cantidad_palabras, cortas, ncortas, largas, nlargas);
    ordenar (cortas, ncortas);
    ordenar (largas, nlargas);

    imprimir_grupo ("original", palabras, cantidad_palabras);
    cout << endl;
    imprimir_grupo ("cortas", cortas, ncortas);
    cout << endl;
    imprimir_grupo ("largas", largas, nlargas);

    return 0;
}

//esta funcion separa palabras y retorna el total
int separar_palabras(char* texto, char* palabras[]){
    char *token = strtok(texto, " ,\n;:-_");
    int i = 0;

    while (token != nullptr){
        palabras[i] = token;
        token = strtok(nullptr, " ,\n;:-_"); //continua analizando la cadena
        i++;
    }

    return i;
}

int longitud_palabra(const char* p){

    int longitud = 0;

    //el puntero p apuntara al primer caracter de cada palabra del texto
    //de modo que es suficiente con encontrar un caracter ' '

    while (*p != '\0' && *p != ' '){
        longitud++;
        p++;
    }

    return longitud;
}

void clasificar(char* palabras[], int n, char* cortas[], int& ncortas, char* largas[], int& nlargas){
    
    //recorrer el arreglo de punteros palabras
    //clasificar segun longitud


    for (int i = 0; i < n; i++){
        int longitud = longitud_palabra(palabras[i]);
        
        if (longitud <= 3){
            cortas[ncortas] = palabras[i];
            ncortas++;
        }

        else {
            largas[nlargas] = palabras[i];
            nlargas++;
        }
    }
}

//esta funcion nos permitira verificar si las palabras no estan repetidas 
//en la frae
int comparar_palabras(const char* a, const char* b){

    //si la letra actual es mayuscula o minuscula, se considera exactamente igual
    while ((*a == *b || *a == *b + 'a' - 'A' || *b == *a + 'a' - 'A') && *a != '\0' && *b != '\0' && *a != ' ' && *b != ' '){
        a++;
        b++;
    }

    return *a - *b;
}

//funcion para ordenar alfabeticamente las palabras 
void ordenar(char* v[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            //se utiliza puntero doble para que no se pase una copia 
            intercambio (&v[j], &v[j+1]);
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n){
    cout << "Palabras " << titulo << ":" << endl;
    cout << endl;
    for (int i = 0; i < n; i++){
        char *p = v[i];
        while (*p != '\0' && *p != ' '){
            cout << *p;
            p++;
        }
        cout << endl;
    }
}

//funcion para intercambiar elementos en el arreglo
void intercambio (char **a, char **b){
    if (comparar_palabras(*a, *b) > 'A' - 'a'){
        char *temp = *a;
        *a = *b;
        *b = temp;  
    }
}