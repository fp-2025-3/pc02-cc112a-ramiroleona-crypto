/*
Implementar un programa en C++ que genere un archivo de texto llamado grafico.txt
El programa debera evaluar la funcion f(x) = sen(5x) para valores x en [0,2pi]:
    -Usar 80 puntos igualmente espaciados
    -Generar un grafico de 21 filas por 80 columnas donde:
        el eje vertical representa valores entre -1 y 1
        el eje horizontal representa el intervalor [0, 2pi]
        la curva se dibuja usando el caracter *
        el eje X se representa con -, el eje Y con |
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*
Para este problema, trabajaremos en modo binario, de modo que facilitaremos el acceso aleatorio y la escritura
con correcciones tras generar el plano necesario.
*/

const double pi = 3.14159;

int main() {

    fstream archivo("grafico.txt", ios::out | ios::binary);

    if (!archivo) {
        cout << "Error al crear el archivo";
        return 1;
    }

    //llenamos el archivo con los ejes

    char caracter;

    for (int i = 0; i < 21; i++){
        caracter = '|';
        archivo.write(reinterpret_cast<char*>(&caracter), 1);
        for (int j = 1; j < 80; j++){
            if (i == 10){
                caracter = '-';
            }
            else {
                caracter = ' ';
            }          
            archivo.write(reinterpret_cast<char*>(&caracter), 1);
        }
        caracter = '\n';
        archivo.write(reinterpret_cast<char*>(&caracter), 1);
    }

    //ahora reubicamos los *
    for (int j = 0; j < 80; j++){

        int lugar = 10 - round(sin(5*j*(2*pi/79))*10);

        //ubicamos la fila junto con los punteros de escritura y lectura 
        archivo.clear();
        archivo.seekp(lugar*81 + j + 1, ios::beg);  
        
        caracter = '*';
        archivo.write(reinterpret_cast<char*>(&caracter), 1);
    }


    archivo.close();

    return 0;
}

