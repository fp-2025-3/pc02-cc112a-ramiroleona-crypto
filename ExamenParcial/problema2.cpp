#include <iostream>
#include <cstring>
using namespace std;

/*
Se desea desarrollar un sistema que controle los resultados de una carrera pedestre. Se tiene un maximo de 
30 corredores. De cada corredor se registra:

Nombre
Tiempo de llegada en segundos
*/

void GenerarRanking (char nombres[][20], int tiempos[], int n);
void MostrarRanking (char nombres[][20], int tiempos[], int n);
int BuscarCorredor (char nombres[][20], int n, char nombre[]);
void MostrarRango (char nombres[][20], int tiempos[], int n, int t_min, int t_max);

int main () {

    int n;

    cout << "Ingrese numero de corredores: "; cin >> n;
    cout << endl;

    if (n >= 1 && n <= 30){
        char nombres[n][20];
        int tiempos[n];

        for (int i = 0; i < n; i++){
            cout << "Nombre del corredor " << i + 1 << ": ";
            cin >> nombres[i];

            cout << "Tiempo (en segundos): ";
            cin >> tiempos[i];
        }

        cout << endl;
        
        GenerarRanking (nombres, tiempos, n);
        cout << "RANKING FINAL\n";
        MostrarRanking (nombres, tiempos, n);

        cout << endl;

        char nombre[20];

        cout << "Ingresar nombre a buscar: ";
        cin >> nombre;
        cout << endl;

        int indice_corredor = BuscarCorredor(nombres, n, nombre);

        if (indice_corredor != -1){
            cout << "Corredor encontrado\n";
            cout << "Posicion: " << indice_corredor + 1 << endl;
            cout << "Tiempo: " << tiempos[indice_corredor] << " segundos\n";
        }

        else {
            cout << "Corredor no encontrado\n";
        }

        cout << endl;

        int t_min;
        int t_max;

        cout << "Ingrese tiempo minimo y maximo: ";
        cin >> t_min;
        cin >> t_max;
        cout << endl;

        cout << "Corredores en el rango [" << t_min << ", " << t_max << "]\n";
        MostrarRango(nombres, tiempos, n, t_min, t_max);
    }

    else {
        cout << "Datos erroneos";
    }

    return 0;
}

void GenerarRanking (char nombres[][20], int tiempos[], int n){
    //para ordenar los corredores de menor a mayor tiempo, utilizaremos el algoritmo burbuja
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (tiempos[j] > tiempos[j+1]){
                //intercambiamos los tiempos
                swap(tiempos[j], tiempos[j+1]);

                //con una variable temporal, usamos strcpy e intercambiamos nombres
                char temp[20];
                strcpy (temp, nombres[j+1]);
                strcpy (nombres[j+1], nombres[j]);
                strcpy (nombres[j], temp);
            }
        }
    }
}

void MostrarRanking (char nombres[][20], int tiempos[], int n){
    //esto se ejecuta una vez que el ranking esta generado
    for (int i = 0; i < n; i++){
        cout << i + 1 << ". " << nombres[i] << " - " << tiempos[i] << " segundos\n";
    }
}

int BuscarCorredor (char nombres[][20], int n, char nombre[]){
    //el orden lo dicta el arreglo temporal
    //asi que adaptaremos una busqueda lineal

    char temp[20];
    int len = strlen(nombre);
    
    for (int i = 0; i < n; i++){
        strcpy (temp, nombres[i]); //copiamos el nombre del arreglo al temporal
        bool encontrado = true; //variable para verificar que se encontro el nombre

        for (int k = 0; k < len + 1; k++){
            if (temp[k] != nombre[k]){
                encontrado = false;
            }
        }

        if (encontrado){
            return i; 
        }
    }

    return -1;
}

void MostrarRango (char nombres[][20], int tiempos[], int n, int t_min, int t_max){
    for (int i = 0; i < n; i++){
        if (tiempos[i] >= t_min && tiempos[i] <= t_max){
            cout << nombres[i] << " - " << tiempos[i] << " segundos\n";
        }
    }
}