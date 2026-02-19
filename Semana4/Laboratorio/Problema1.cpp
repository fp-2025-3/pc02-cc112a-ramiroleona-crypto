#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/*
Implementar un programa que realice las siguientes tareas sobre una frase ingresada por el usuario:

1.1. Leer una frase de longitud desconocida.

1.2. Almacenar la frase usando asignación dinámica exacta (ni más ni menos memoria).

1.3. Normalizar la frase:

- Eliminar espacios múltiples.

- Convertir todas las letras a minúsculas

1.4. Contar cuántas palabras tiene la frase.

1.5. Construir dinámicamente un arreglo de palabras, donde cada palabra es un char* independiente.

1.6. Mostrar cada palabra junto con su longitud.

1.7. Liberar toda la memoria dinámica correctamente.
*/

char * leerFrase (){
    char temp[100];

    cout << "Ingrese una frase: ";
    //damos lectura a la frase
    cin.getline(temp, 100);

    //calculamos su longitud
    int len = strlen(temp);

    //creamos dinamicamente el arreglo para almacenar uno a uno
    char *frase = new char[len+1];
    for (int i = 0; i < len; i++){
        *(frase+i) = *(temp+i);
    }

    //aniadimos el caracter nulo manualmente
    *(frase + len) = '\0';

    return frase;
}

char * normalizarFrase (char *frase){
    int len = strlen(frase);
    char *temp = new char [len + 1];
    int i = 0; //este indice lo usamos para movernos en la cadena
    int j = 0; //este otro servira para calcular la longitud de la frase normalizada

    //corresponde analizar todos los casos posibles, incluyendo multiples espacios

    while (frase[i] != '\0'){

        //si el caracter actual no es un espacio
        while (frase[i] != '\0' && !isspace(frase[i])){
            temp[j] = tolower(frase[i]);
            i++;
            j++;
        }

        /*
        Para una frase como "     Hola   Mundo ", el bucle avanzaría hasta ubicarse en H, donde almacenaria
        la palabra Hola en minuscula, hasa encontrarse con 3 espacios consecutivos.
        Para dicho caso, sería conveniente introducir una variable auxiliar que convierta todos los espacios
        en uno solo.
        */

        if (i == 0 && isspace(frase[i])){
            while (isspace(frase[i])){
                i++;
            }
        }

        if (i != 0 && isspace(frase[i])){

           
            while (isspace(frase[i])){
                //actualizamos el indice hasta llegar a la siguiente letra o al nulo
                i++;
            }

            //verificamos que no llegamos al nulo
            if (frase[i] != '\0'){
                temp[j] = ' ';
                j++;
            }

        }
    }

    temp[j] = '\0';

    char *normalizada = new char[j+1];
    strcpy(normalizada, temp);
    delete [] temp;
    return normalizada;
}

int contarPalabras (char *frase){
    int cont = 0;
    bool estoyPalabra = false;

    for (int i = 0; frase[i] != '\0'; i++){
        if (!isspace(frase[i]) && !estoyPalabra){
            cont++;
            estoyPalabra = true;
        }
        if (isspace(frase[i])){
            estoyPalabra = false;
        }
    }

    return cont;
}

char ** separarPalabras (char *frase, int cantidad){
    char **palabras = new char*[cantidad];;
    int i = 0;//para recorrer la frase
    int j = 0;//para manipular indices de palabras[]

    while (frase[i] != '\0'){
        //si es espacio, avanzamos
        while (isspace(frase[i])){
            i++;
        }

        /*
        una vez que llegamos a un lugar que no es un espacio, asignamos
        un indice de inicio a ese caracter actual e inicializamos la longitud
        */
        int inicio = i;
        int len = 0;

        /*
        mientras dicho lugar no sea el caracter nulo y no sea un espacio,
        actualizamos tanto i como la longitud
        */
        while(frase[i] != '\0' && !isspace(frase[i])){
            i++;
            len++;
        }

        //con la longitud completa una vez estamos en el nulo o espacio, redimensionamos
        palabras[j] = new char[len+1];

        /*
        ahora copiamos la palabra completa desde el caracter de inicio copiado,
        y lo hacemos tantas veces como la longitud
        */
        for (int k = 0; k < len; k++){
            palabras[j][k] = frase[inicio+k];
        }
        //al ultimo lugar le damos el caracter nulo
        palabras[j][len] = '\0';
        j++;
    }

    return palabras;
}

void mostrarPalabras(char **palabras, int cantidad){
    for (int i = 0; i < cantidad; i++){
        cout << palabras[i] << "\t" << strlen(palabras[i]) << endl;
    }
}

void LiberarMemoria(char **palabras, int cantidad){
    for (int i = 0; i < cantidad; i++){
        delete [] palabras[i];
        palabras[i] = nullptr;
    }
    delete [] palabras;
    palabras = nullptr;
} 

int main () {

    char *frase = leerFrase();//debo liberar memoria

    char *normalizada = normalizarFrase(frase);//debo liberar memoria

    int cantidad = contarPalabras(normalizada);

    char **palabras = separarPalabras(normalizada, cantidad);

    mostrarPalabras(palabras, cantidad);

    //mostramos la frase normalizada
    cout << "Frase normalizada: " << normalizada;

    LiberarMemoria (palabras, cantidad);

    delete [] frase;
    delete [] normalizada;
    frase = nullptr;
    normalizada = nullptr;

    return 0;
}