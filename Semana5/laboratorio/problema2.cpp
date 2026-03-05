#include <iostream>
using namespace std;

/*
Desarrollar una estructura llamada 'Estudiante' que contenga
como atributos 'nombre' y 'nota'
Posteriormente, crear un arreglo de tipo 'Estudiante' con 
capacidad para almacenar 'n' elementos. 
Solicite al usuario ingresar los nombres y las notas de los 'n'
estudiantes, para luego imprimir el nombre y la nota del estudiante
con la calificacion mas alta.
*/

struct Estudiante {
    char nombre[30];
    float nota;
};

void estudianteSuperior (Estudiante *lista, int n);

int main () {

    int n;

    cout << "Ingrese el numero de estudiantes: "; cin >> n;

    Estudiante *lista = new Estudiante [n];

    for (int i = 0; i < n; i++){
        cin.ignore();
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": "; cin.getline(lista[i].nombre, 30);
        cout << "Ingrese la nota del estudiante " << i + 1 << ": "; cin >> lista[i].nota;
    }

    estudianteSuperior (lista, n);

    delete [] lista;
    lista = nullptr;

    return 0;
}

void estudianteSuperior (Estudiante *lista, int n){

    int indice = 0;

    for (int i = 0; i < n; i++){
        if (lista[i].nota >= lista[indice].nota){
            indice = i;
        }
    }

    cout << "El estudiante con la mayor nota es: " << lista[indice].nombre << endl;
    cout << "Nota: " << lista[indice].nota << endl;
}