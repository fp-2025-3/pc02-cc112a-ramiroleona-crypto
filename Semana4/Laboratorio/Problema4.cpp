#include <iostream>
#include <climits>
using namespace std;

/*
Dado un arreglo unidimensional A de n (máximo 15) números enteros positivos. Se desea dividir el arreglo en segmentos contiguos, cumpliendo las siguientes condiciones:

    Cada segmento debe contener al menos un elemento.

    El valor de un segmento se define como el producto de todos sus elementos.

    El costo total de una segmentación es la suma de los valores de todos los segmentos.

Implementar una función recursiva para determinar el costo mínimo posible que se puede obtener al segmentar el arreglo.
*/

int costoMinimo (int arr[], int n, int pos);

int main () {

    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int costo = costoMinimo (arr, n, 0);

    cout << "El costo minimo es " << costo;

    return 0;
}

int costoMinimo (int arr[], int n, int pos){

    //el caso base de las iteraciones
    if (pos == n){
        return 0;
    }

    //fijamos un minimo para comparar
    int minimo = INT_MAX;
    int producto = 1;

    //esta seccion retornara un minimo global siempre
    for (int i = pos; i < n; i++){
        producto *= arr[i];

        int costo_actual = producto + costoMinimo (arr, n, i + 1);

        if (costo_actual < minimo){
            minimo = costo_actual;
        }
    }

    /*
    Veamos el procedimiento para el arreglo {1, 2, 3},
    cuando llamamos a costoMinimo (arr, 3, 0):
        minimo1 = INT_MAX
        i = 0:
            producto1 = arr[0] = 1
            costo_actual = 1 + costoMinimo (arr, 3, 0 + 1):
                                minimo2 = INT_MAX
                                i = 1:
                                    producto2 = arr[1] = 2
                                    costo_actual = 2 + costoMinimo (arr, 3, 1+1):
                                                        minimo3 = INT_MAX
                                                        i = 2:
                                                            producto3 = arr[2] = 3
                                                            costo_actual = 3 + 0 = 3
                                                            como 3 < minimo3,
                                                            te retorna 3
                                    costo_actual = 2 + 3 = 5
                                    como 5 < minimo2,
                                    minimo2 = 5
                                i = 2:
                                    producto2 = 2*3 = 6
                                    costo_actual = 6 + costoMinimo (arr, 3, 2 + 1) = 6 + 0
                                    costo_actual = 6
                                    6 > 5, asi que el minimo2 no se actualiza
                                te retorna 5
            costo_actual = 1 + 5 = 6
            como 6 < minimo1,
            minimo1 = 6
        i = 1:
            producto1 = 1*2 = 2
            costo_actual = 2 + costoMinimo (arr, 3,  1 + 1):
            ya sabemos que costoMinimo (arr, 3, 2) retorna 3
            costo_actual = 2 + 3 = 5
            como 5 < 6,
            minimo1 = 5
        i = 2:
            producto1 = 2*3 = 6
            costo_actual = 6 + costoMinimo (arr, 3, 2 + 1) = 6 + 0 = 6
            pero 6 > 5, asi que el minimo no se actualiza

        Finalmente, la funcion retorna 5 como minimo   

    */

    return minimo;
}