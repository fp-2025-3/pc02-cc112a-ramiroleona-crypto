#include <iostream>
using namespace std;

struct Polinomio {
    int grado;
    int *coeficientes;
};

//los coeficientes estan en orden decreciente

void MostrarPolinomio (Polinomio p);
Polinomio * sumar (Polinomio *p);
Polinomio * multiplicar (Polinomio *p);

int main () {

    Polinomio *p = new Polinomio [3];

    p[0].grado = 2;
    p[1].grado = 1;
    p[2].grado = 2;

    p[0].coeficientes = new int [3];
    p[1].coeficientes = new int [2];
    p[2].coeficientes = new int [3];

    p[0].coeficientes[0] = 8;
    p[0].coeficientes[1] = 2;
    p[0].coeficientes[2] = 2;

    p[1].coeficientes[0] = -3;
    p[1].coeficientes[1] = -5;

    p[2].coeficientes[0] = 6;
    p[2].coeficientes[1] = 0;
    p[2].coeficientes[2] = 8;

    Polinomio *suma = sumar(p);
    Polinomio *producto = multiplicar(p);

    cout << "Polinomio 1: ";
    MostrarPolinomio (p[0]);
    cout << endl;

    cout << "Polinomio 2: ";
    MostrarPolinomio (p[1]);
    cout << endl;

    cout << "Polinomio 3: ";
    MostrarPolinomio (p[2]);
    cout << endl;
    cout << endl;


    cout << "Suma de los tres polinomios: ";
    MostrarPolinomio (*suma);
    cout << endl;

    cout << "Producto de los tres polinomios: ";
    MostrarPolinomio (*producto);
    cout << endl;

    delete [] suma->coeficientes;
    delete [] producto->coeficientes;

    suma->coeficientes = nullptr;
    producto->coeficientes = nullptr;

    delete suma;
    delete producto;

    suma = nullptr;
    producto = nullptr;

    delete [] p[0].coeficientes;
    delete [] p[1].coeficientes;
    delete [] p[2].coeficientes;

    p[0].coeficientes = nullptr;
    p[1].coeficientes = nullptr;
    p[2].coeficientes = nullptr;

    delete [] p;

    p = nullptr;

    return 0;
}

void MostrarPolinomio (Polinomio p) {
    if (p.coeficientes[0] != 0){
        cout << p.coeficientes[0] << "x^" << p.grado;
    }

    for (int i = 1; i < p.grado; i++){
        if (p.coeficientes[i] > 0){
            cout << " + " << p.coeficientes[i] << "x^" << p.grado - i;
        }

        if (p.coeficientes[i] < 0){
            cout << " " << p.coeficientes[i] << "x^" << p.grado - i;
        }

    }

    cout << " + " << p.coeficientes[p.grado]; 
}

Polinomio * sumar (Polinomio *p){
    Polinomio *resultado = new Polinomio;

    //buscamos el grado maximo para crear la cantidad total
    int grado_maximo = 0;
    for (int i = 0; i < 3; i++){
        if (p[i].grado > grado_maximo){
            grado_maximo = p[i].grado;
        }
    }

    resultado->grado = grado_maximo;
    resultado->coeficientes = new int [grado_maximo + 1];
    
    for (int i = 0; i < resultado->grado+1; i++){
        resultado->coeficientes[i] = 0;
    }

    int indice = 0;

    while (indice < 3){
        for (int i = 0; i < p[indice].grado+1; i++){
            resultado->coeficientes[resultado->grado - p[indice].grado + i] += p[indice].coeficientes[i];
        }
        indice++;
    }

    return resultado;
}

Polinomio * multiplicar (Polinomio *p){
    Polinomio *resultado = new Polinomio;

    //el grado resultante sera la suma de los grados de los 3 polinomios
    resultado->grado = p[0].grado+p[1].grado+p[2].grado;
    resultado->coeficientes = new int [resultado->grado+1];
    
    for (int i = 0; i < resultado->grado+1; i++){
        resultado->coeficientes[i] = 0;
    }

    //para manejar todos los resultados, debemos combinar fijando un primer polinomio

    for (int i = 0; i < p[0].grado + 1; i++){
        for (int j = 0; j < p[1].grado + 1; j++){
            for (int k = 0; k < p[2].grado + 1; k++){
                resultado->coeficientes[i+j+k] += (p[0].coeficientes[i])*(p[1].coeficientes[j])*(p[2].coeficientes[k]);
            }
        }
    }

    return resultado;
}