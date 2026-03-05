#include <iostream>
#include <climits>
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

    bool fila_5_dominante = esFilaDominante(M, 4);
    if (fila_5_dominante){
        cout << "La fila 5 SI ";
    }

    else {
        cout << "La fila 5 NO ";
    }

    cout << "es fila dominante\n";

    int columnas_criticas = contarColumnasCriticas(M);

    cout << "La matriz tiene " << columnas_criticas << " columnas criticas\n";

    bool Es_Escalonada = esMatrizEscalonada(M);

    if (Es_Escalonada){
        cout << "La matriz SI ";
    }

    else {
        cout << "La matriz NO ";
    }

    cout << "es escalonada\n";

    int valor_nucleo = valorNucleo (M);

    if (valor_nucleo != -1){
        cout << "El valor nucleo de la matriz es " << valor_nucleo;
    }

    else {
        cout << "La matriz no tiene nucleo";
    }

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
    int primer_indice = -1;
    //recorremos cada fila y ubicamos al primer elemento no nulo
    for (int i = 0; i < N; i++){
        int indice_nulo = -1;
        for (int j = 0; j < N; j++){
            if (*(*(M+i)+j) != 0){
                indice_nulo = j;
                break;
            }
        }

        //suponiendo que el inidice nulo no se actualiza porque todos los elementos eran 0:
        if (indice_nulo != -1){
            //si el indice_nulo es menor o igual al almacenado, entonces no es escalonada
            if (indice_nulo <= primer_indice){
                return false;
            }
            else {
                primer_indice = indice_nulo;
            }
        }
    }
    return true;
}

int valorNucleo(int (*M)[N]){
    /*
    De acuerdo con la definicion de valor nucleo, este sera unico. Veamos el caso para una matriz 2x2:
    a b
    c d
    Si suponemos que b y c son nucleos simultaneos, se cumple:
    a < b < d y d < c < a
    Por transitividad, esto conduce a lo siguiente:
    a < b < d < c < a => a < a, lo cual es contradictorio
    
    Partiendo de que dos nucleos no podrian estar en la misma fila o columna, podriamos asemejar nuestro analisis
    al de una matriz 2 x 2 de la siguiente forma:
    
    a ... b
    .     .
    .     . 
    .     .
    c ... d

    Si quisieramos indicar que b y c son nucleos, el analisis previo arroja la misma contradiccion.
    Con ello en claro, podemos estar seguros de detener las iteraciones en 
    cuanto hallemos un nucleo.
    */

    //empezaremos encontrando el maximo de una fila, y luego verificamos si es el minimo de su columna
    for (int i = 0; i < N; i++){
        int maximo_fila = - INT_MAX; //para almacenar el primer maximo de la fila
        bool es_maximo = false; //para asegurar que el maximo sea absoluto
        int columna;

        for (int j = 0; j < N; j++){
            //verificamos que no sean iguales
            if (*(*(M+i)+j) == maximo_fila){
                es_maximo = false;
            }
            
            //con esto ubicamos el maximo elemento, pero corremos el riesgo de que este repetido
            if (*(*(M+i)+j) > maximo_fila){
                columna = j; //almacenamos la columna
                maximo_fila = *(*(M+i)+j);
                es_maximo = true;
            }
        }

        if (es_maximo){
            bool es_minimo = true;

            for (int k = 0; k < N; k++){
                if (k != i && maximo_fila >= *(*(M+k)+columna)){
                    es_minimo = false;
                    break;
                }
            }

            if (es_minimo){
                return maximo_fila;
            }
        }
    }

    return -1;
}