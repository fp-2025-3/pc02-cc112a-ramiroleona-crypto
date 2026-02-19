#include <iostream>
#include <cmath>
using namespace std;

/*
Implementar una estructura llamada 'Punto' que defina las tres coordenadas (x, y, z) de un punto en un espacio tridimensional.
Luego, crear dos instancias de la estructura 'Punto' y solicitar al usuario ingresar las coordenadas de ambos puntos desde el teclado.
Calcule la distancia euclidiana entre los dos puntos y muestre el resultado en pantalla.
*/

struct Punto {
    float x;
    float y;
    float z;
};

float distanciaPuntos (Punto *x1, Punto *x2);

int main () {

    Punto *x1 = new Punto;
    Punto *x2 = new Punto;

    cout << "Ingrese las coordenas del primer punto:\n";
    cout << "X: "; cin >> x1->x; 
    cout << "Y: "; cin >> x1->y; 
    cout << "Z: "; cin >> x1->z;
    cout << "Ingrese las coordenadas del segundo punto:\n";
    cout << "X: "; cin >> x2->x; 
    cout << "Y: "; cin >> x2->y; 
    cout << "Z: "; cin >> x2->z;
    cout << "La distancia entre los dos puntos es: " << distanciaPuntos (x1, x2) << endl;

    delete x1;
    delete x2;
    x1 = nullptr;
    x2 = nullptr;

    return 0;
}

float distanciaPuntos (Punto *x1, Punto *x2){
    return sqrt(pow(x1->x-x2->x,2) + pow(x1->y-x2->y,2) + pow(x1->z-x2->z,2));
}