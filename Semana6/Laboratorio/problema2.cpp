/*
Implementar un programa que lea datos numéricos almacenados en un archivo de texto notas.txt

15
18
12
09
20
14
16
11
a continuación:

Procese la información desde el archivo.

Genere un reporte estadístico en un nuevo archivo reporte.txt. Dicho archivo debe contener:

Cantidad total de estudiantes.

Promedio general.

Nota más alta.

Nota más baja.

Cantidad de estudiantes aprobados (nota ≥ 10).

Cantidad de estudiantes desaprobados (nota < 10).

Formato de salida del archivo reporte.txt

REPORTE GENERAL
------------------------
Total estudiantes: X
Promedio: X
Mayor nota: X
Menor nota: X
Aprobados: X
Desaprobados: X
*/

#include <iostream>
#include <fstream>
using namespace std;

int main () {

    //abrimos el archivo de lectura
    ifstream entrada ("input/notas.txt");

    ofstream salida ("output/reporte.txt");

    if (!entrada || !salida){
        cerr << "Ha ocurrido un error";
        return 1;
    }

    int totalEstudiantes = 0;
    double nota;
    double promedio = 0.0;
    double notaBaja = 20;
    double notaAlta = 0;
    int cantidadAprobados = 0;

    while (entrada >> nota){
        totalEstudiantes ++;
        promedio += nota;
        if (nota < notaBaja){
            notaBaja = nota;
        }
        if (nota > notaAlta){
            notaAlta = nota;
        }
        if (nota >= 10){
            cantidadAprobados++;
        }
    }

    entrada.close();

    //escribimos en el archivo salida

    if (totalEstudiantes == 0){
        cerr << "El archivo no contenia informacion";
        salida.close();
        return 1;
    }

    salida << "REPORTE GENERAL\n";
    salida << "------------------------\n";
    salida << "Total estudiantes: " << totalEstudiantes << endl;
    salida << "Promedio: " << promedio / totalEstudiantes << endl;
    salida << "Mayor nota: " << notaAlta << endl;
    salida << "Menor nota: " << notaBaja << endl;
    salida << "Aprobados: " << cantidadAprobados << endl;
    salida << "Desaprobados: " << totalEstudiantes - cantidadAprobados << endl;

    salida.close();

    return 0;
}