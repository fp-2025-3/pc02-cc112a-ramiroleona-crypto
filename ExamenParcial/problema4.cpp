#include <iostream>
using namespace std;

/*
Queremos gestionar la informacion de los estudiantes con 2 arreglos dinamicos y paralelos:
codigos[] y promedios[]
*/

void agregar_duplicar (int *codigos, float *promedios, int codigo_nuevo, float promedio_nuevo, int tamanio, int capacidad);
void eliminar_redimensionar (int *codigos, float *promedios, int tamanio);

int main () {

    //capacidad inicial
    int n = 4;

    int *codigos = new int [n];
    float *promedios = new float [n];
    int tamanio = 0; //empiezan vacios

    cout << "Estudiantes registrados:\n";
    //vamos a registrar un total de 5 estudiantes para verificar el funcionamiento
    for (int i = 0; i < n + 1; i++){
        int codigo; 
        float promedio;
        cout << "Codigo: "; cin >> codigo;
        cout << "Promedio: "; cin >> promedio;
        cout << endl;
        agregar_duplicar(codigos, promedios, codigo, promedio, tamanio, n);
        tamanio++;
    }

    cout << endl;

    cout << "Filtrando estudiantes desaprobados...\n";
    cout << endl;
    cout << "Estudiantes aprobados:\n";
    eliminar_redimensionar(codigos, promedios, tamanio);
    for (int i = 0; i < tamanio; i++){
        cout << "Codigo: " << codigos[i];
        cout << "Promedio" << promedios[i];
        cout << endl;
    }


    return 0;
}

void agregar_duplicar (int *codigos, float *promedios, int codigo_nuevo, float promedio_nuevo, int tamanio, int capacidad){
    //si el arreglo iguala la capacidad maxima, se redimensiona todo
    if (tamanio == capacidad){

        //almacenamos dinamicamente los datos actuales en temporales
        int *temp_codigos = new int [tamanio];
        float *temp_promedios = new float [tamanio];

        for (int i = 0; i < tamanio; i++){
            temp_codigos[i] = codigos[i];
            temp_promedios[i] = promedios[i];
        }

        //eliminamos y duplicamos
        delete [] codigos;
        delete [] promedios;

        codigos = new int [2*capacidad];
        promedios = new float [2*capacidad];

        //retornamos datos
        for (int i = 0; i < tamanio; i++){
            codigos[i] = temp_codigos[i];
            promedios[i] = temp_promedios[i] ;
        }

        //borramos los temporales
        delete [] temp_codigos;
        delete [] temp_promedios;

        temp_codigos = nullptr;
        temp_promedios = nullptr;
    }

    //aniadimos al nuevo estudiante
    codigos[tamanio] = codigo_nuevo;
    promedios[tamanio] = promedio_nuevo;
}

void eliminar_redimensionar (int *codigos, float *promedios, int tamanio){
    //creamos temporales

    int *temp_codigos = new int [tamanio];
    float *temp_promedios = new float [tamanio];

    //copiamos datos de acuerdo a la condicion
    int i = 0; //para contar aprobados
    for (int j = 0; j < tamanio; i++){
        if (promedios[j] >= 10.0){
            temp_codigos[i] = codigos[j];
            temp_promedios[i] = promedios[j];
            i++;
        }
    }

    //eliminamos y redimensionamos con el total de aprobados
    delete [] codigos;
    delete [] promedios;

    codigos = new int [i];
    promedios = new float [i];

    //recuperamos los datos originales
    for (int j = 0; j < i; j++){
        codigos[j] = temp_codigos[j];
        promedios[j] = temp_promedios[j] ;
    }

    //eliminamos temporales
    delete [] temp_codigos;
    delete [] temp_promedios;

    temp_codigos = nullptr;
    temp_promedios = nullptr;
}

