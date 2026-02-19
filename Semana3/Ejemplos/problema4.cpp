#include <iostream>
using namespace std;

int main () {

    /*
    char arr1[5] = {'H', 'o', 'l', 'a', '!'};
    Aquí no se aniadio el caracter nulo, y por lo tanto
    no funcionara cout
    */
    char arr1[5] = {'H', 'o', 'l', 'a', '\0'};
    char arr2[5] = "Hola";
    //una cadena válida debe terminar en '\0'

    cout << arr1 << endl;
    cout << arr2 << endl;
    return 0;
}