#include <iostream>
using namespace std;

int main () {

    char palabra[] = "PERU";
    char *p = palabra;

    *(p+1);

    /*
    Como p apunta a 'P', hacer p + 1 nos lleva a 'E'
    Internamente se avanza 1 byte (sizeof(char))
    */

    return 0;
}