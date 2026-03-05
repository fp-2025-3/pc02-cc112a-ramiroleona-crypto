#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

/*
Se requiere un programa para registrar la perfomance de 5 selecciones en un torneo de 100 partidos cada una.
Para cada seleccion se debe almacenar:
    Nombre
    Partidos ganados, empatados y perdidos
    Goles a favor
    Goles en contra
    Puntaje total
    Diferencia de goles
    Rendimiento
Generar aleatoriamente y de forma coherente: PG, PE, PP
*/

struct Seleccion {
    string nombre;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int DG;
    int puntaje;
    double rendimiento;
};

const int n = 5;

Seleccion * generarEquipos ();
void ordenar (Seleccion * equipos);
void mostrarTabla (Seleccion * equipos);

int main () {

    srand(time(NULL));

    Seleccion *equipos = generarEquipos();
    ordenar (equipos);
    mostrarTabla(equipos);

    delete [] equipos;
    equipos = nullptr;

    /*
    para generar los resultados y que estos sean coherentes, seguiremos la siguiente logica:
        1- Para los resultados del equipo 1, asumiremos que los primeros 25 corresponden a los partidos con el equipo 2, 
        mientras que los siguientes 25 corresponden a los partidos contra el equipo 3, y así sucesivamente.
        De este modo, una vez generados los resultados del equipo 1, el equipo 2 generara los resultados sus 75 partidos restantes.
        En la siguiente, el equipo 3 generara los resultados de los 50 restantes.
        El equipo 4 generara los resultados de los ultimos 25.
        El equipo 5 no generara nada.
    */


    return 0;
}

Seleccion * generarEquipos (){

    Seleccion *equipos = new Seleccion [n];
    //inicializamos en 0 todo lo que vayamos a actualizar constantemente
    for (int i = 0; i < n; i++){
        equipos[i].nombre = "Pais_" + to_string(i);
        equipos[i].PG = 0;
        equipos[i].PE = 0;
        equipos[i].PP = 0;
        equipos[i].GF = 0;
        equipos[i].GC = 0;
    }

    for (int i = 0; i < n; i++){
        //lo que tenemos que generar aleatoriamente son los PG, PE, PP, GF y GC
        for (int j = i + 1; j < n; j++){
            for (int k = 0; k < 25; k++){
                int Goles_Anotados = rand () % (6);
                int Goles_Recibidos = rand () % (6);

                if (Goles_Anotados == Goles_Recibidos){
                    equipos[i].PE++;
                    equipos[j].PE++;
                }

                else if (Goles_Anotados > Goles_Recibidos){
                    equipos[i].PG++;
                    equipos[j].PP++;
                }

                else {
                    equipos[i].PP++;
                    equipos[j].PG++;
                }

                equipos[i].GF += Goles_Anotados;
                equipos[i].GC += Goles_Recibidos;
                equipos[j].GC += Goles_Anotados;
                equipos[j].GF += Goles_Recibidos;
            }
        }        
    }

    for (int i = 0; i < n; i++){
        equipos[i].DG = equipos[i].GF - equipos[i].GC;
        equipos[i].puntaje = 3*equipos[i].PG + equipos[i].PE;
        equipos[i].rendimiento = 100.0*(equipos[i].puntaje/300.0);
    }

    return equipos;
}

void ordenar (Seleccion * equipos){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (equipos[j].puntaje > equipos[j+1].puntaje 
                || (equipos[j].puntaje == equipos[j+1].puntaje && equipos[j].DG > equipos[j+1].DG)
                || (equipos[j].puntaje == equipos[j+1].puntaje && equipos[j].DG == equipos[j+1].DG && equipos[j].GF > equipos[j+1].GF)){
                swap(equipos[j], equipos[j+1]);
            }
        }
    }
}

void mostrarTabla (Seleccion * equipos) {
    cout << "Seleccion" << "\t" << "PG" << "\t" << "PE" << "\t" << "PP" << "\t" << "GF" <<  "\t" << "GC" <<  "\t" << "DG" << "\t" << "Pts" << "\t" << "Rend(%)\n";
    for (int i = n-1; i >= 0; i--){
        cout << equipos[i].nombre << "\t" << "\t" << equipos[i].PG << "\t" << equipos[i].PE << "\t" << equipos[i].PP << "\t" << equipos[i].GF << "\t" << equipos[i].GC << "\t" << equipos[i].DG << "\t" << equipos[i].puntaje << "\t" << setprecision(3) << showpoint << equipos[i].rendimiento << endl;
    }
    cout << endl;

    cout << "CAMPEON: " << equipos[n-1].nombre << " | " << "Puntaje: " << equipos[n-1].puntaje << " | " << "DG: " << equipos[n-1].DG << " | " << "Rendimiento: " << equipos[n-1].rendimiento << endl;
}
    
