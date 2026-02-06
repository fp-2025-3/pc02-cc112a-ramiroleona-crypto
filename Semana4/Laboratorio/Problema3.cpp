#include <iostream>
using namespace std;

/*
La escuela desea analizar el rendimiento de sus estudiantes del curso de Fundamentos de Programación. 
Para ello se cuenta con la siguiente información de N estudiantes:

    Código del estudiante (entero, único)
    Nota final (0 – 20)
    Número de inasistencias

La información no está ordenada y proviene de diferentes fuentes.

3.1. Implementar una función que:

- Lea los datos de N estudiantes

- Almacene la información en arreglos paralelos

int codigo[N];
float nota[N];
int faltas[N];

3.2. Ordenar los estudiantes de mayor a menor nota, manteniendo la relación entre:

código ↔ nota ↔ faltas

Condición: si dos estudiantes tienen la misma nota, el que tiene menos faltas va primero.

void ordenarPorNota(float nota[], int codigo[], int faltas[], int n);

3.3. Mostrar el ranking académico:

    Top 5 estudiantes

    Promedio del curso

    Número de desaprobados (nota < 10)

3.4. Implementar: Búsqueda secuencial: Buscar un estudiante por su código e imprimir: Nota, Faltas, Posición en el ranking

3.5. Reordenar los datos por código ascendente (ya no por nota).

Use Selection Sort o Insertion Sort

3.6. Una vez ordenado por código: Implementar búsqueda binaria

int busquedaBinaria(int codigo[], int n, int clave);
*/

void ordenarPorNota(float nota[], int codigo[], int faltas[], int n);
void MostrarRankingAcademico (float nota[], int codigo[], int faltas[], int n);
void BusquedaSecuencial (float nota[], int codigo[], int faltas[], int n, int codigo_clave);
void OrdenamientoCodigo (float nota[], int codigo[], int faltas[], int n);
int busquedaBinaria(int codigo[], int n, int clave);

int main () {

    int n = 10;
    float notas[] = {19.5, 8.9, 2.0, 20.0, 15.4, 7.2, 10.1, 12.4, 17.8, 19.5};
    int codigo[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int faltas[] = {4, 0, 0, 0, 0, 4, 3, 2, 1, 5};

    ordenarPorNota (notas, codigo, faltas, n);
    MostrarRankingAcademico (notas, codigo, faltas, n);

    int codigo1 = 38;
    BusquedaSecuencial (notas, codigo, faltas, n, codigo1);
    OrdenamientoCodigo (notas, codigo, faltas, n);

    int codigo2 = 38;
    int indice = busquedaBinaria (codigo, n, codigo2);
    cout << "El indice actual es " << indice << endl;

    return 0;
}

void ordenarPorNota(float nota[], int codigo[], int faltas[], int n){
    //burbuja
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if ((nota[j] > nota[j+1]) || (nota[j] == nota[j+1] && faltas[j] < faltas[j+1])){
                swap(nota[j], nota[j+1]);
                swap(faltas[j], faltas[j+1]);
                swap(codigo[j], codigo[j+1]);
            }
        }
    }
}

void MostrarRankingAcademico (float nota[], int codigo[], int faltas[], int n){
    //para mostrar el ranking, necesitamos el top 5 de estudiantes, promedio general y numero de desaprobados
    float promedio_general = 0.0;
    int desaprobados = 0;

    cout << "Ranking academico:\n";
    cout << "PUESTO ------ CODIGO ------ NOTA ------ FALTAS\n";

    for (int i = 0; i < n; i++){
        if (i < n && i >= n - 5){
            cout << n - i << "             " << codigo[i] << "             " << nota[i] << "          " << faltas[i] << endl;
        }

        if (nota[i] < 10.0){
            desaprobados++;
        }
        promedio_general += nota[i];
    }

    cout << "Hay " << desaprobados << " estudiantes desaprobados\n";
    cout << "El promedio general del curso es " << promedio_general/n << "\n";

}

void BusquedaSecuencial (float nota[], int codigo[], int faltas[], int n, int codigo_clave){
    //ya que los codigos no tienen un orden especifico, no podemos trabajar con algo como busqueda binaria
    //tenemos que utilizar busqueda lineal
    for (int i = 0; i < n; i++){
        if (codigo[i] == codigo_clave){
            cout << "El estudiante con codigo " << codigo_clave << " tiene " << nota[i] << " de nota y " << faltas[i] << " faltas en total. Su posicion en el ranking es " << n - i << endl;
            break;
        }
    }    
}

void OrdenamientoCodigo (float nota[], int codigo[], int faltas[], int n){
    for (int i = 0; i < n - 1; i++){
        int indice_max = i;
        for (int j = 0; j < n - i; j++){
            if (codigo[j] > codigo[indice_max]){
                indice_max = j;
            }
        }
        swap(nota[indice_max], nota[n-i-1]);      
        swap(faltas[indice_max], faltas[n-i-1]);
        swap(codigo[indice_max], codigo[n-i-1]);
    }
}

int busquedaBinaria(int codigo[], int n, int clave){
    int inicio = 0; 
    int fin = n - 1;

    while (inicio <= fin){
        int medio = (inicio + fin)/2;

        if (codigo[medio] == clave){
            return medio;
        }

        if (codigo[medio] > clave){
            fin = medio - 1;
        }

        else {
            inicio = medio + 1;
        }
    }

    return -1;
}