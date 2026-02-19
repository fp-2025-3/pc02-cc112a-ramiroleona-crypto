#include <iostream>
#include <climits>
using namespace std;

int costoMaximo(int arr[], int n, int pos);

int main () {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maximo = costoMaximo(arr, n, 0);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "El costo maximo es " << maximo << "\n";

    return 0;
}

int costoMaximo(int arr[], int n, int pos){

    //caso base, cuando hemos recorrido todo el arreglo 
    if (pos == n){
        return 0;
    }

    //utilizaremos como maximo principal el negativo del maximo entero que soporta el tipo int
    //para ello, hacemos uso de la libreria climits
    int maximo = -INT_MAX;

    //inicializamos el producto en 1
    int producto = 1;

    //iniciamos el caso recursivo evaluando todas las combinaciones
    for (int i = pos; i < n; i++){
        //el producto se actualiza en cada iteracion tras finalizar las llamadas recursivas que maximizan un caso
        producto *= arr[i];

        //esta variable se actualiza en cada iteracion una vez que se realiza el backtracking
        int costo_actual = producto + costoMaximo(arr, n, i + 1);

        if (costo_actual > maximo){
            maximo = costo_actual;
        }
    }

    return maximo;
}

/*
    Para el arreglo {2, 1, 3}:
    costo = costo_maximo (arr, 3, 0)
        No estamos en el caso base
        maximo1 = -INT_MAX
        producto1 = 1

        i = 0:
            producto1 = 2
            costo_actual1 = 2 + costo_maximo (arr, 3, 1)
                                No esta en el caso base
                                maximo2 = -INT_MAX
                                producto2 = 1

                                i = 1:
                                    producto2 = 1
                                    costo_actual2 = 1 + costo_maximo (arr, 3, 2)
                                                        No esta en el caso base
                                                        maximo3 = -INT_MAX
                                                        producto3 = 1

                                                        i = 2:
                                                            producto3 = 3
                                                            costo_actual3 = 3 + costo_maximo (arr, 3, 3) = 3 + 0 = 3 (caso base)
                                                            Como costo_actual = 3 es mayor a maximo3, maximo3 = 3
                                                        Este caso retorna 3, pues solo hay i = 2
                                    costo_actual2 = 1 + 3 = 4
                                    como 4 > maximo2, maximo2 = 4
                                i = 2:
                                    producto2 = 1*3 = 3
                                    costo_actua2 = 3 + costo_maximo (arr, 3, 3) = 3
                                    como 3 < 4, maximo2 se mantiene en 4
                                retorna 4
            costo_actual1 = 2 + 4 = 6
            como 6 > 4, maximo1 = 6
        i = 1: 
            producto1 = 2*1 = 2
            costo_actual1 = 2 + costo_maximo(arr, 3, 2)
                                No esta en el caso base
                                maximo4 = -INT_MAX
                                producto4 = 1
                                
                                i = 2:
                                    producto4 = 3
                                    costo_actual4 = 3 + costo_maximo (arr, 3, 3) = 3
                                    como 3 > maximo4, maximo4 = 3
                                retorna 3
            costo_actual1 = 2 + 3 = 5
            como 5 < 6, maximo1 no se actualiza, sigue siendo 6
        i = 2:
            producto1 = 2*3 = 6
            costo_actual1 = 6 + costo_maximo (arr, 3, 3) = 6 + 0 = 6
            como 6 = 6, no se actualiza nada

        Finalmente, el algoritmo retorna 6

    */
