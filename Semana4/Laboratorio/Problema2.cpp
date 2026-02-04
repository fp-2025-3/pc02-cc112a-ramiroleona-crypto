#include <iostream>
using namespace std;

const int N = 5;
/*
Se tiene una matriz estática cuadrada de enteros M de tamaño fijo N × N, con N ≥ 3.
La matriz se declara en la función main de la siguiente forma:

La matriz representa una estructura de relaciones entre filas y columnas.

Utilice aritmética de punteros e implemente las siguientes funciones:

    bool esFilaDominante(int (*M)[N], int fila);

    Una fila se considera dominante si cada uno de sus elementos es estrictamente mayor que el elemento correspondiente de todas las demás filas en la misma columna.

    int contarColumnasCriticas(int (*M)[N]);

    Una columna se considera crítica si la suma de sus elementos es mayor que la suma de cualquier fila de la matriz.

    La función debe retornar la cantidad total de columnas críticas.

    bool esMatrizEscalonada(int (*M)[N]);

    Una matriz es escalonada si, para cada fila, la posición del primer elemento no nulo aparece en una columna estrictamente mayor que la del primer elemento no nulo de la fila anterior.

    int valorNucleo(int (*M)[N]);

    El núcleo de la matriz es un elemento que cumple simultáneamente:

        Es el máximo de su fila

        Es el mínimo de su columna

    La función debe retornar el valor del núcleo. Si no existe ningún elemento que cumpla ambas condiciones, retornar -1.

*/

bool esFilaDominante(int (*M)[N], int fila);
int contarColumnasCriticas(int (*M)[N]);
bool esMatrizEscalonada(int (*M)[N]);
int valorNucleo(int (*M)[N]);

int main () {

    int M[N][N] = {
        {0, 0, 7, 8, 9},
        {0, 0, 0, 5, 6},
        {0, 0, 0, 0, 4},
        {1, 2, 3, 4, 5},
        {9, 8, 7, 6, 5}
    };

    return 0;
}

bool esFilaDominante(int (*M)[N], int fila){ 
    /*
    aqui necesitamos recorrer cada elemento de la fila (por columnas), 
    y verificar que sea estrictamente mayor que los elementos de esa 
    columna en las otras filas
    */
    int columna = 0;
    while (columna < N){
        for (int i = 0; i < N; i++){
            if (i != fila && *(*(M+fila)+columna) <= *(*(M+i)+columna)){
                return false;
            }
        }
        columna++;
    }
    return true;
}

int contarColumnasCriticas(int (*M)[N]){
    int suma_filas[N] = {0};
    int suma_columnas[N] = {0};
    int columnas_criticas = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            *(suma_filas+i) += *(*(M+i)+j);
            *(suma_columnas+i) += *(*(M+j)+i);
        }
    }

    int columna = 0;

    while (columna < N){
        int filas_menores = 0;
        for (int i = 0; i < N; i++){
            if(*(suma_columnas + columna) > *(suma_filas + i)){
                filas_menores++;
            }
        }

        if (filas_menores == N){
            columnas_criticas++;
        }
        columna++;
    }

    return columnas_criticas;
}

bool esMatrizEscalonada(int (*M)[N]){

    int indices_nulos;

    for (int i = 0; i < N; i++){
        
    }

}

int valorNucleo(int (*M)[N]){

}