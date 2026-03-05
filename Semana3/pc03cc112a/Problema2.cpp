#include <iostream>
using namespace std;

void imprimir_texto (char *texto){
    char *p = texto;
    while (*p != '\0'){
        cout << *p;
        p++;
    }
    cout << endl;
}

int PalabrasQueEmpiezanConVocal (char *texto){
    int cantidad = 0;
    char *p = texto;

    while (*p != '\0'){
        if ((p == texto && (*p == 'a' || *p == 'A' || *p == 'e' || *p == 'E' || *p == 'i' 
            || *p == 'I'|| *p == 'o' || *p == 'O' || *p == 'u' || *p == 'U'))){
            cantidad++;
        }
        if ( p > texto && *(p-1) == ' ' && (*p == 'a' || *p == 'A' || *p == 'e' || *p == 'E' || *p == 'i' 
            || *p == 'I'|| *p == 'o' || *p == 'O' || *p == 'u' || *p == 'U')){
            cantidad++;
        }
        p++;
    } 
    return cantidad;
}

int main(){

    char texto[] = "Este es   un ejemplo en C++ END";

    int cantidad = PalabrasQueEmpiezanConVocal(texto);

    cout << "Texto: ";
    imprimir_texto(texto);
    cout << "Numero de palabras que comienzan con vocal: " << cantidad;
}

