#include <iostream>
using namespace std;

/*
Ejercicio 2:
Implementar una agenda de contactos.

Cada contacto tiene los siguientes datos:
a. Nombre
b. Fecha de nacimiento (estructura Fecha)

La cantidad de contactos es desconocida:

1. Reservar memoria dinamica para N contactos
2. Leer datos
3. Mostrar los nacidos en un anio especifico  
*/

//estructura para las fechas
struct Fecha {
    int dia; 
    int mes; 
    int anio;
};

//estructura para el contacto, con fecha anidada
struct Contacto {
    char nombre[20];
    Fecha nacimiento;
};



Contacto * ReservarMemoria (int n);
void MostrarDatos (Contacto *contactos, int n);
void FiltroPorNacimientos (Contacto *&contactos, int &n, int anio);

int main(){

    int N;

    cout << "Ingrese la cantidad de contactos: "; cin >> N;

    //reservamos memoria
    Contacto *contactos = ReservarMemoria (N);

    //leemos datos
    for (int i = 0; i < N; i++){
        cout << "Contacto " << i + 1 << ":\n";
        cout << "Nombre: "; cin >> contactos[i].nombre;
        cout << "Dia de nacimiento: "; cin >> contactos[i].nacimiento.dia; 
        cout << "Mes de nacimiento: "; cin >> contactos[i].nacimiento.mes;
        cout << "Anio de nacimiento: "; cin >> contactos[i].nacimiento.anio; cout << "\n";
    }

    cout << "Contactos actuales:\n";

    //mostramos datos
    MostrarDatos (contactos, N);

    int anio;


    cout << "Ingrese un anio para filtrar la busqueda:\n"; cin >> anio; 
    cout << "Filtrando busqueda...\n";

    FiltroPorNacimientos (contactos, N, anio);

    if (N == 0){
        cout << "No se encontraron coincidencias";
    }

    else {
        cout << "Contactos encontrados:\n";
        MostrarDatos (contactos, N);
    }

    delete [] contactos;
    contactos = nullptr;
    
    return 0;
}

Contacto * ReservarMemoria (int n){
    return new Contacto [n];
}

void MostrarDatos (Contacto *contactos, int n){
    for (int i = 0; i < n; i++){
        cout << "Nombre: " << contactos[i].nombre; cout << "\n";
        cout << "Dia de nacimiento: " << contactos[i].nacimiento.dia; cout << "\n";
        cout << "Mes de nacimiento: " << contactos[i].nacimiento.mes; cout << "\n";
        cout << "Anio de nacimiento: " << contactos[i].nacimiento.anio; cout << "\n";
        cout << "--------------------------------------------------------------\n";
    }
}

void FiltroPorNacimientos (Contacto *&contactos, int &n, int anio){
    Contacto *temp = new Contacto [n];
    int filtrados = 0;

    //guardamos en el arreglo temporal la informacion de quienes tienen el anio escogido
    for (int i = 0; i < n; i++){
        if (contactos[i].nacimiento.anio == anio){
            temp[filtrados] = contactos[i];
            filtrados++;
        }
    }

    //liberamos la memoria actual
    delete [] contactos;
    
    //redimensionamos 
    n = filtrados;
    contactos = temp;
}