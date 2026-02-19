#include <iostream>
#include <cstring> //strlen() strcpy() strcat() strcmp()
using namespace std;

int my_strlen (const char *str);
char * my_strcpy (char * destino, const char * fuente);
char * my_strcat (char * destino, const char * fuente);
int my_strcmp (const char *cadena1, const char * cadena2);

int main () {

    char cadena1[] = "fundamentos de programacion";
    char *p1 = cadena1;

    int longitud1 = my_strlen (p1);
    cout << "La longitud de la cadena1 es " << longitud1 << endl;
    cout << "Longitud con strlen: " << strlen(cadena1) << endl;
    cout << endl;

    char destino1[50];
    char destino2[50];
    const char fuente1[] = "fundamentos de programacion";
    cout << "Copia con my_strcpy: " << my_strcpy(destino1, fuente1) << endl;
    cout << "Copia con strcpy: " << strcpy(destino2, fuente1) << endl;
    cout << endl;
    
    char destino3[50] = "Teoria local de ";
    char destino4[50] = "Teoria local de ";
    const char fuente2[] = "superficies";
    cout << "Concatenacion con my_strcat: " << my_strcat(destino3, fuente2) << endl;
    cout << "Concatenacion con strcat: " << strcat(destino4, fuente2) << endl;
    cout << endl;

    char comparar1[] = "Astrofisica";
    char comparar2[] = "Astronomia";
    char comparar3[] = "Astronomia";
    char comparar4[] = "Astrologia";
    cout << "Comparar 1 y 2 con my_strcmp: " << my_strcmp(comparar1, comparar2) << endl;
    cout << "Comparar 1 y 2 con strcmp: " << strcmp(comparar1, comparar2) << endl;
    cout << endl;
    cout << "Comparar 2 y 3 con my_strcmp: " << my_strcmp(comparar2, comparar3) << endl;
    cout << "Comparar 2 y 3 con strcmp: " << strcmp(comparar2, comparar3) << endl;
    cout << endl;
    cout << "Comparar 1 y 4 con my_strcmp: " << my_strcmp(comparar1, comparar4) << endl;
    cout << "Comparar 1 y 4 con strcmp: " << strcmp(comparar1, comparar4) << endl;
    cout << endl;

    return 0;
}

//funcion de longitud strlen
int my_strlen (const char *str){
    int longitud = 0;
    while (*str != '\0'){
        longitud++;
        str++;
    }
    //devolvemos la longitud dada
    return longitud;

    /*
    Tambien:
    const char * p = str;
    while (*p != '\0'){
        p++;
    }
    return p - str;
    */
}

//funcion de copia strcpy
char * my_strcpy (char * destino, const char * fuente){
    char * puntero = destino;
    while (*fuente != '\0'){
        *destino = *fuente;
        destino++;
        fuente++;
    }
    *destino = '\0';
    return puntero;
}

//funcion de concatenar strcat
char * my_strcat (char * destino, const char * fuente){
    char *inicio = destino;

    //avanzamos hacia el final
    while (*destino != '\0'){
        destino++;
    }

    while (*fuente != '\0'){
        *destino = *fuente;
        destino++;
        fuente++;
    }

    *destino = '\0';

    return inicio;
}

//funcion de comparar strcmp
int my_strcmp (const char *cadena1, const char * cadena2){

    while (*cadena1 == *cadena2 && *cadena1 != '\0' && *cadena2 != '\0'){
        cadena1++;
        cadena2++;
    }

    //esto nos dara 0 si son iguales, un positivo si el primer elemento diferente de cadena 1 es mayor que el de cadena 2, y viceversa en negativo
    return *cadena1 - *cadena2;

}
