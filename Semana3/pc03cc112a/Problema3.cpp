#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
Utilizando doble puntero, escriba un programa que genere una matriz cuadrada de orden 9, donde cada fila
y cada columna sea una permutacion de los elementos del arreglo {1, 2, 3, 4, 5, 6, 7, 8, 9}.
El programa debe:
1. Generar la matriz inicial
2. Solicitar al usuario un numero de fila y un numero de columna
3. Modificar la matriz para que las filas queden desplazadas de modo que el valor seleccionado en (i, j) 
ocupe la columna j
*/

void GenerarMatriz (int **matriz);
void ImprimirMatriz (int **matriz, int n);
void ModificarMatriz (int **matriz, int fila, int columna, int n);

int main (){

    srand(time(NULL));
    //aperturamos la matriz
    int matriz[9][9];
    int *filas[9];

    for (int i = 0; i < 9; i++){
        filas[i] = matriz[i];
    }

    GenerarMatriz(filas);

    cout << "Matriz inicial:\n";
    ImprimirMatriz (filas, 9);

    int i;
    int j;

    cout << "Fila inicial (1-9): ";
    cin >> i;
    cout << endl;
    cout << "Columna inicial (1-9): ";
    cin >> j;
    cout << endl;

    cout << "Valor seleccionado: " << *(*(filas+i-1)+j-1) << endl;
    cout << "Matriz final:\n";
    ModificarMatriz(filas, i, j, 9);
    ImprimirMatriz(filas, 9);

    return 0;
}

void GenerarMatriz (int **matriz){
    for (int i = 0; i < 9; i++){
        int numeros_aleatorios[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int *numeros = numeros_aleatorios;

        /*
        en este caso, mezclaremos de forma aleatoria el arreglo e intercambiaremos numeros
        con un indice aleatorio
        */

        for (int j = 0; j < 9; j++){
            int indice_aleatorio = rand ()%(9);
            //intercambiamos el elemento
            int temp = *(numeros + j);
            *(numeros + j) = *(numeros + indice_aleatorio);
            *(numeros + indice_aleatorio) = temp; 
        }

        for (int k = 0; k < 9; k++){
            *(*(matriz+i)+k) = *(numeros+k);
        }
    }
}

void ImprimirMatriz (int **matriz, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << *(*(matriz+i)+j) << "  "; 
        }
        cout << endl;
    }
}

void ModificarMatriz (int **matriz, int fila, int columna, int n){
    for (int i = 0; i < n; i++){
        //aqui se empieza a desplazar el arreglo, poniendo como condicion que la columna coincida con el valor esperado
        while (*(*(matriz + i) + (columna-1)) != *(*(matriz + (fila-1)) + (columna-1))){
            int ultimo = *(*(matriz + i) + (n-1));
            for (int k = n-1; k > 0; k--){
                *(*(matriz + i) + k) = *(*(matriz + i) + k - 1);
            }
            *(*(matriz + i)) = ultimo;
        }
    }
}
