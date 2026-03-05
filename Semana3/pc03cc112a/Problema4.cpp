#include <iostream>
using namespace std;

int guardaDirecciones (char *texto, char **indice);
int comparar (const char *a, const char *b);
void ordenaIndice (char **indice, int n);
void imprimir (char *texto, char **indice, int n);

int main(){

    char texto[] = "los punteros no se copian se referencian y se ordenan";
    char *indice[30];
    char **indice_inicial = indice;

    int cantidad = guardaDirecciones(texto, indice_inicial);
    ordenaIndice(indice_inicial, cantidad);
    imprimir (texto, indice_inicial, cantidad);

    return 0;
}

int guardaDirecciones (char *texto, char **indice){
    int cantidad = 0;
    char *p = texto;

    while (*p != '\0'){
        if ((p == texto && *p != ' ') || (*(p-1) == ' ' && *p != ' ')){
            *(indice+cantidad) = p;
            cantidad++;
        }
        p++;
    }    

    return cantidad;
}

int comparar (const char *a, const char *b){
    while (*a==*b && *a != ' ' && *b != ' ' && *a != '\0' && *b != '\0'){
        a++;
        b++;
    }
    return *a - *b;
}

void ordenaIndice (char **indice, int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (comparar(*(indice+j), *(indice+j+1)) > 0){
                swap(*(indice+j), *(indice+j+1));
            }
        }
    }
}

void imprimir (char *texto, char **indice, int n){
    for (int i = 0; i < n; i++){
        char *puntero = texto;
        int localizacion = 0;
        char *p = *(indice+i);

        while (*puntero != '\0'){
            if (puntero == p){
                break;
            }
            localizacion++;
            puntero++;
        }

        //con estos pasos se obtendran la longitud de cada palabra aislada y se podra lograr una mejor presentacion
        int longitud = 0;
        char *temp = p;
        while (*temp != '\0' && *temp != ' '){
            cout << *temp;
            temp++;
            longitud++;
        }

        
        for (int k = longitud; k < 15; k++){
            cout << ' ';
        }
    
        cout << "(posicion " << localizacion << ")\n";
    }
}