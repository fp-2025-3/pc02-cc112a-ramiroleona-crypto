#include <iostream>
using namespace std;

/*
Se desea gestionar estudiantes, donde no se conoce de antemano cuantos son en un curso. 
Cada estudiante tiene codigo y promedio
Escribir un programa que 
1. solicite al usuario la cantidad de estudiantes N
2. reservar memoria dinamicamente para los N estudiantes 
3. leer los datos 
4. mostrar unicamente los aprobados (promedio >= 10.0)
5. liberar memoria correctamente
*/

struct Estudiante {
    int codigo;
    float promedio;
};

void filtrarEstudiantes (Estudiante * &estudiantes, int &n);
void mostrarEstudiantes (Estudiante *estudiantes, int n);

int main () {

    int N;

    cout << "Indique la cantidad de estudiantes que desea agregar: "; cin >> N; cout << endl;

    Estudiante *estudiantes = new Estudiante [N];

    for (int i = 0; i < N; i++){
        cout << "Estudiante " << i + 1 << ":\n";
        cout << "Codigo: "; cin >> estudiantes[i].codigo;
        cout << "Promedio: "; cin >> estudiantes[i].promedio; cout << "\n";
    }

    cout << "Estudiantes registrados:\n";
    mostrarEstudiantes (estudiantes, N);

    cout << endl;

    cout << "Retirando a los desaprobados...\n";

    filtrarEstudiantes (estudiantes, N);

    cout << "Estudiantes aprobados:\n";
    mostrarEstudiantes (estudiantes, N);

    delete [] estudiantes;
    estudiantes = nullptr;

    return 0;
}

void filtrarEstudiantes (Estudiante * &estudiantes, int &n){
    Estudiante *temp = new Estudiante [n];
    int cantidad_aprobados = 0;

    //guardamos en el arreglo temporal la informacion de los aprobados
    for (int i = 0; i < n; i++){
        if (estudiantes[i].promedio >= 10.0){
            temp[cantidad_aprobados] = estudiantes[i];
            cantidad_aprobados++;
        }
    }

    //liberamos la memoria actual
    delete [] estudiantes;
    
    //redimensionamos 
    n = cantidad_aprobados;
    estudiantes = temp;

}

void mostrarEstudiantes (Estudiante *estudiantes, int n){
    for (int i = 0; i < n; i++){
        cout << "Estudiante " << i + 1 << ":\n";
        cout << "Codigo: " << estudiantes[i].codigo; cout << "\n";
        cout << "Promedio: " << estudiantes[i].promedio; cout << "\n";
    }
}