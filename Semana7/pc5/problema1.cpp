#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main () {

    ifstream entrada("input/notas.txt");
    ofstream reporte("output/reporte.txt");

    if (!reporte || !entrada){
        cout << "El archivo no encontro" << endl;
        return 1;
    }

    int total_estudiantes = 0;
    double promedio_total = 0.0;

    //datos para guardar al estudiante con mayor promedio
    double promedio_mayor = 0.0;
    int id_mayor;
    char nombre_mayor[20];
    
    //datos para guardar al estudiante con menor promedio
    double promedio_menor = 20.0;
    int id_menor;
    char nombre_menor[20];

    //datos de lectura secuencial
    int id;
    char nombre[20];
    int nota1;
    int nota2;
    int nota3;
    
    while (entrada >> id >> nombre >> nota1 >> nota2 >> nota3){
        double promedio = (nota1 + nota2 + nota3)/3.0;
        reporte << id << " " << nombre << " " << promedio;
        if (nota1 < 5 || nota2 < 5 || nota3 < 5){
            reporte << " DESAPROBADO POR REGLA ACADEMICA";
        }
        else {
            if (promedio >= 10){
            reporte << " APROBADO";
            }
            else {
                reporte << " DESAPROBADO";
            }
        }

        if (promedio > promedio_mayor){
            promedio_mayor = promedio;
            strcpy(nombre_mayor, nombre);
            id_mayor = id;
        }

        if (promedio < promedio_menor){
            promedio_menor = promedio;
            strcpy(nombre_menor, nombre);
            id_menor = id;
        }

        //actualizamos la cantidad de estudiantes y el promedio
        reporte << endl;
        total_estudiantes++;
        promedio_total += promedio;
    }

    entrada.close();

    promedio_total /= total_estudiantes;

    reporte << endl;
    //escribimos los datos
    reporte << "REPORTE FINAL\n";
    reporte << "Total de estudiantes: " << total_estudiantes << endl;
    reporte << "Promedio general del curso: " << promedio_total << endl;
    reporte << "El estudiante con mayor promedio es " << id_mayor << " || " << nombre_mayor << " || " << promedio_mayor << endl;
    reporte << "El estudiante con menor promedio es " << id_menor << " || " << nombre_menor << " || " << promedio_menor << endl;

    reporte.close();

    cout << "El reporte se creo exitosamente";

    return 0;
}