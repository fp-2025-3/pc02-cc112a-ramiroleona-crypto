#include <iostream>
#include <fstream>
using namespace std;

/*
Una pequeña tienda desea registrar las ventas diarias de la semana. Implementar un programa que solicite al usuario el monto de ventas de cada día y los almacene en un archivo llamado ventas.txt

Cada valor debe almacenarse en una línea diferente.

Luego de registrar los 7 montos, el programa debe calcular:

Total de ventas.

Promedio semanal.

Día con mayor venta.

Día con menor venta.

Finalmente, debe escribir al final del mismo archivo
*/

const int DIAS = 7;

int main () {

    //abrimos un archivo en modo escritura
    ofstream archivo ("output/ventas.txt", ios::app); //usamos app para agregar
    
    if (!archivo) {
        cout << "Error al abrir el archivo";
        return 1;
    }

    double total = 0.0;
    double menorVenta;
    double mayorVenta;

    double venta;

    for (int i = 1; i <=DIAS; i++){
        //usamos flujo de consola para leer los datos 
        cout << "Ingrese la venta del dia: " << i << ": ";
        cin >> venta;

        //Luego usamos flujo de archivo para escribir en el archivo
        archivo << venta << endl;
        total += venta;

        if (i==1){
            mayorVenta = venta;
            menorVenta = venta;
        }

        else {
            if (venta > mayorVenta){
                mayorVenta = venta;
            }

            if (venta < menorVenta){
                menorVenta = venta;
            }
        }
    }

    //guardamos las estadísticas al final
    archivo << "-------------------------\n";
    archivo << "RESUMEN\n";
    archivo << "Total: " << total << endl;
    archivo << "Promedio: " << total / DIAS << endl;
    archivo << "Mayor venta: " << mayorVenta << endl;
    archivo << "Menor venta: " << menorVenta << endl;

    archivo.close();



    return 0;
}