#include <iostream>
using namespace std;

struct Estudiante {
    int codigo;
    float promedio;
    char sexo;
};

struct Fecha {
    int dia;
    int mes;
    int anio;
};

void mostrar (Estudiante e1);
void aumentarPromedio (Estudiante &e1);
float calcularPromedio (Estudiante estudiantes[], int n);

int main () {

    Estudiante e1 = {25694, 18.2, 'M'};
    Estudiante e2;

    e2.codigo = 25678;
    e2.promedio = 20.0;
    e2.sexo = 'F';

    Estudiante *ptr;

    ptr = &e2;

    Estudiante e3;

    cout << "Ingrese el codigo"; cin >> e3.codigo; cout << endl;
    cout << "Ingrese el promedio"; cin >> e3.promedio; cout << endl;
    cout << "Ingrese el sexo"; cin >> e3.sexo; cout << endl;

    return 0;
}

//Paso por valor (copiando contenido)
void mostrar (Estudiante e1){
    cout << e1.codigo;
}

//Paso por referencia (util para programas eficientes y para modificar datos)
void aumentarPromedio (Estudiante &e1) {
    e1.promedio += 1.0;
}

float calcularPromedio (Estudiante estudiantes[], int n) {
    float promedio;

    for (int i = 0; i < n; i++){
        promedio += estudiantes[i].promedio;
    }

    return promedio/n;
}