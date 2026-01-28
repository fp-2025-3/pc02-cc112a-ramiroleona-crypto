#include <iostream>
using namespace std;

int main() {
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl;
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;
}

/*
Qué valores numéricos se imprimirán?
Los que han sido asignados por ASCII en la memoria

¿Por qué 'A' y 'a' no tienen el mismo valor?
Porque no están representados por el mismo valor numerico 

¿Un char es realmente un carácter o un número?
El compilador no ve letras, solo números

¿Cuántos bytes ocupa un char en memoria? 
1 byte

*/