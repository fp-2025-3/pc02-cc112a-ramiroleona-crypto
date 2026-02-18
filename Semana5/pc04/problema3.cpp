#include <iostream>
#include <cstring>
using namespace std;

/*
Crear una estructura Producto e implementar las siguientes funciones:
Producto crearProducto (int codigo, const char *nombre, double precio, int stock);
Producto * crearInventario (int n);
Producto * buscarProducto (Producto *inventario, int n, int codigoBuscado);
void liberarInventario (Producto *inventario, int n);
void mostrarInventario (Producto *inventario, int n);
*/

struct Producto {
    int codigo;
    char *nombre;
    double precio;
    int stock;
};

//PROTOTIPOS
Producto crearProducto (int codigo, const char *nombre, double precio, int stock);
Producto * crearInventario (int n);
Producto * buscarProducto (Producto *inventario, int n, int codigoBuscado);
void liberarInventario (Producto *inventario, int n);
void mostrarInventario (Producto *inventario, int n);

int main () {

    int n = 5;
    Producto *inventario = crearInventario (n);
    cout << endl;
    mostrarInventario (inventario, n);

    int codigoBuscado;

    cout << "Ingrese un codigo a buscar: "; cin >> codigoBuscado;
    cout << "Buscando producto con codigo " << codigoBuscado << "...\n";
    Producto *buscar = buscarProducto (inventario, n, codigoBuscado);

    if (buscar != nullptr){
        cout << "Producto encontrado: " << buscar->nombre << " | " << "Precio: " << buscar->precio << endl;
        
    } 

    else {
        cout << "Producto no encontrado\n";
    }

    liberarInventario (inventario, n);

    return 0;
}

//funcion para crear cada producto con los datos ya conocidos
Producto crearProducto (int codigo, const char *nombre, double precio, int stock){
    Producto p; //creamos la variable

    //Asignamos los datos. Hacemos uso de <cstring> para trabajar con strlen, de modo que nos 
    //aseguramos de tener una cadena dinamica
    p.codigo = codigo;
    int len = strlen(nombre);

    //reservamos espacio para la cadena
    p.nombre = new char [len + 1];
    for (int i = 0; i < len; i++){
        p.nombre[i] = nombre[i];
    }

    //colocamos manualmente el caracter nulo
    p.nombre[len] = '\0';
    p.precio = precio;
    p.stock = stock;

    //retornamos la variable
    return p;
}

//funcion para crear el inventario dado un tamanio n
Producto * crearInventario (int n){
    //reservamos memoria dinamica
    Producto *inventario = new Producto [n];

    //ingresamos los nombres de los articulos manualmente utilizando una variable dinamica auxiliar 
    //nombre de tamanio maximo 100
    for (int i = 0; i < n; i++){
        char *nombre = new char [100];
        cout << "Ingresar nombre de articulo "<< i + 1 << ": "; cin >> nombre;
        int codigo = 100 + i;
        double precio = 10.5*(1+i);
        int stock = 5*(i+1);
        inventario[i] = crearProducto (codigo, nombre, precio, stock);

        //borramos la variable y asignamos nullptr (buena practica)
        delete [] nombre;
        nombre = nullptr;
    }

    //retornamos el puntero inventario
    return inventario;
}

//funcion para buscar producto dado un codigo ingresado
Producto * buscarProducto (Producto *inventario, int n, int codigoBuscado){

    //utilizamos busqueda lineal
    for (int i = 0; i < n; i++){
        if (inventario[i].codigo == codigoBuscado){
            //retornamos la direccion actual de encontrarse el codigo
            return &inventario[i];
        }
    }

    //si no encontramos nada, retornamos nullptr
    return nullptr;
}

//funcion para liberar inventario
void liberarInventario (Producto *inventario, int n){

    //liberamos cada cadena nombre y la hacemos nullptr (buena practica)
    for (int i = 0; i < n; i++){
        delete [] inventario[i].nombre;
        inventario[i].nombre = nullptr;

    }

    //borramos el inventario y asignamos nullptr
    delete [] inventario;
    inventario = nullptr;
}

//funcion para mostrar el inventario
void mostrarInventario (Producto *inventario, int n){
    cout << "      INVENTARIO\n";
    for (int i = 0; i < n; i++){
        cout << "Codigo: " << inventario[i].codigo << " | " << "Nombre: " << inventario[i].nombre << " | " << "Precio: " << inventario[i].precio << " | " << "Stock: " << inventario[i].stock << endl;
    }
    cout << endl;
}