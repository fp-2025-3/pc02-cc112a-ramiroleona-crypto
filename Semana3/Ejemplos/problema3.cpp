#include <iostream>
using namespace std;

int main (){

    //Convertir mayusculas en minusculas
    char c = 'D';
    c = c + ('a'-'A');

    //'a' - 'A' = 32

    cout << c;

    return 0;
}