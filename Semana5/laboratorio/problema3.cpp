#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
Se requiere un programa para registrar la performance de las selecciones que juegan
en un torneo, en el que cada seleccion juega 100 partidos. Para ello, haga una estructura
que guarde informacion de una seleccion:

El nombre de la seleccion, puntos totales obtenidos, partidos jugados, ganados (PG), empatados (PE) 
y perdidos (PP), ademas el rendimiento, que es el porcentaje de puntos obtenidos del total posible.
Genere aleatoriamente la cantidad de PG, PE y PP para cada seleccion de un arreglo de 5 selecciones.
Imprima un cuadro final, destacando la seleccion de mayor rendimiento.
*/

struct Seleccion {
    string nombre;
    int puntaje;
    int PG;
    int PE;
    int PP;
    float rendimiento;
};

int main () {

    srand(time(NULL));

    Seleccion *lista = new Seleccion [5]; 

    /*
    Al momento de crear los datos, debe tenerse en consideracion lo siguiente:
    1. El total de partidos empatados en la lista debe de ser 100
    2. La suma total de partidos ganados y perdidos en toda la lista debe de ser 400
    */

    //creamos los datos numericos
    int i = 0;
    int suma_empatados = 0;
    int suma_ganados_perdidos = 0;

    for (int j = 0; j < 5; j++){
        lista[j].nombre = "Pais_Seleccion" + to_string(j);
    }

    while (i < 4){
        if (suma_empatados > 100 || suma_ganados_perdidos > 400){
            lista[i].PG = rand () % (101);
            suma_ganados_perdidos += lista[i].PG;
            lista[i].PP = rand () % (101 - lista[i].PG);
            suma_ganados_perdidos += lista[i].PP;
                
            lista[i].PE = 100 - lista[i].PG - lista[i].PP;
            suma_empatados += lista[i].PE; 
            
            lista[i].puntaje = 3*lista[i].PG + 1*lista[i].PE;
            lista[i].rendimiento = 100.0*(lista[i].puntaje/300.0);
            i++;
        }

        else {
            i = 0;
        } 
    }

    //cuando i sea 4
    lista[i].PG = rand () % (401 - suma_ganados_perdidos);
    suma_ganados_perdidos += lista[i].PG;
    lista[i].PP = 400 - suma_ganados_perdidos;
    lista[i].PE = 100 - suma_empatados;
    lista[i].puntaje = 3*lista[i].PG + 1*lista[i].PE;
    lista[i].rendimiento = 100.0*(lista[i].puntaje/300.0);

    int indice = 0;
    cout << "Seleccion" << "\t" << "PG" << "\t" << "\t" << "PP" << "\t" << "PE" <<  "\t" << "Puntaje" <<  "\t" << "Rendimiento\n";
    for (int i = 0; i < 5; i++){
        cout << lista[i].nombre << "\t" << lista[i].PG << "\t" << lista[i].PP << "\t" << lista[i].PE << "\t" << lista[i].puntaje << "\t" << setprecision(3) << showpoint << lista[i].rendimiento << endl;
        if (lista[i].rendimiento > lista[indice].rendimiento){
            indice = i;
        }
    }

    cout << "La seleccion con mejor rendimiento es:\n";
    cout << lista[indice].nombre << endl;
    cout << "Rendimiento: " << lista[indice].rendimiento << endl;

    delete [] lista;
    lista = nullptr;

    return 0;
}