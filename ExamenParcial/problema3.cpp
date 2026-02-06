#include <iostream>
using namespace std;

/*
Sea M una matriz cuadrada de enteros de orden NxN, utilizando exclusivamente punteros
a) Implementar la funcion
bool esFilaDominanteEstricta (int (*M)[N], int f);
b) Implementar la funcion
bool esFilaFuertementeDominante (int (*M)[N], int f);
*/

const int N = 4;

bool esFilaDominanteEstricta (int (*M)[N], int f);
bool esFilaFuertementeDominante (int (*M)[N], int f);

int main () {

    int M[N][N] = 
    {{2, 3, 1, 4},
     {1, 2, 3, 2},
     {5, 6, 7, 8},
     {0, 1, 2, 1}};

    cout << "Fila    Dominante Estricta      Fuertemente Dominante\n";
    cout << "-----------------------------------------------------\n";
    
    for (int i = 0; i < N; i++){
        cout << i << "       ";

        if (esFilaDominanteEstricta (M, i)){
            cout << "SI";
        }

        else {
            cout << "NO";
        }

        cout << "                      ";

        if (esFilaFuertementeDominante (M, i)){
            cout << "SI";
        }

        else {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}

bool esFilaDominanteEstricta (int (*M)[N], int f){

    //variable que controla la condicion de que al menos un elemento de la fila es estrictamente mayor 
    //que los de su misma columna
    bool estrictamenteMayor = false;

    //empezamos a recorrer las columnas, este bucle solo sera completado si todos verifican la 1ra condicion 
    for (int j = 0; j < N; j++){
        //una vez que se tiene un j, comparamos los elementos de esa columna en cada fila distinta
        int contador = 0; //si este contador llega a N - 1, se estara verificando la segunda condicion

        for (int i = 0; i < N; i++){
            if (i != f && *(*(M+f)+j) < *(*(M+i)+j)){
                return false;
            }

            if (i != f && *(*(M+f)+j) > *(*(M+i)+j)){
                contador++;
            }
        }

        //condicion para dar por comprobada la segunda condicion
        if (contador == 3){
            estrictamenteMayor = true;
        }
    }

    if (estrictamenteMayor){
        return true;
    }

    return false;
}

bool esFilaFuertementeDominante (int (*M)[N], int f){
    //filtro para la primera condicion
    if (esFilaDominanteEstricta(M, f)){

        int suma_fila = 0;

        for (int j = 0; j < N; j++){
            suma_fila += *(*(M+f)+j);
        }

        //aqui verificamos la segunda condicion
        for (int i = 0; i < N; i++){
            //siempre que no estemos en la fila evaluada
            if (i != f){
                //iniciamos una suma especial
                int suma_actual = 0;
                for (int j = 0; j < N; j++){
                    suma_actual += *(*(M+i)+j);
                }

                //si la suma resulta ser mayor o igual que la suma de la fila evaluada, se retorna falso
                if (suma_actual >= suma_fila){
                    return false;
                }
            }
        }

        //si se supero el bucle, se retorna verdadero
        return true;
    }

    return false;

}
