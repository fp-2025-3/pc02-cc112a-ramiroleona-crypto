#include <iostream>
using namespace std;

int main () {

    /*funciones de entrada de datos
    char nombre[10];
    cin >> nombre;

    Esto es erroneo

    - No controla tamanio
    - Puede sobreescribir memoria
    - Provoca buffer overflow
    */

    //MEJOR USO: cin.getline:

    char frase[50];
    cin.getline(frase, 50);

    cout << frase << endl;

    return 0;
}