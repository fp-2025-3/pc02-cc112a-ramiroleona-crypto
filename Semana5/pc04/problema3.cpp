#include <iostream>
#include <cstring>
using namespace std;

struct Producto {
    int codigo;
    char *nombre;
    double precio;
    int stock;
};

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
    
    delete buscar;
    buscar = nullptr;

    liberarInventario (inventario, n);

    return 0;
}

Producto crearProducto (int codigo, const char *nombre, double precio, int stock){
    Producto p;
    p.codigo = codigo;
    int len = strlen(nombre);
    p.nombre = new char [len + 1];
    for (int i = 0; i < len; i++){
        p.nombre[i] = nombre[i];
    }
    p.nombre[len] = '\0';
    p.precio = precio;
    p.stock = stock;

    return p;
}

Producto * crearInventario (int n){
    Producto *inventario = new Producto [n];

    for (int i = 0; i < n; i++){
        char *nombre = new char [100];
        cout << "Ingresar nombre de  articulo "<< i + 1 << ": "; cin >> nombre;
        int codigo = 100 + i;
        double precio = 10.5*(1+i);
        int stock = 5*(i+1);
        inventario[i] = crearProducto (codigo, nombre, precio, stock);
        delete [] nombre;
        nombre = nullptr;
    }

    return inventario;
}

Producto * buscarProducto (Producto *inventario, int n, int codigoBuscado){

    for (int i = 0; i < n; i++){
        if (inventario[i].codigo == codigoBuscado){
            Producto *encontrado = new Producto;
            encontrado = &inventario[i];
            return encontrado;
        }
    }

    return nullptr;
}

void liberarInventario (Producto *inventario, int n){
    for (int i = 0; i < n; i++){
        delete [] inventario[i].nombre;
        inventario[i].nombre = nullptr;

    }

    delete [] inventario;
    inventario = nullptr;
}

void mostrarInventario (Producto *inventario, int n){
    cout << "      INVENTARIO\n";
    for (int i = 0; i < n; i++){
        cout << "Codigo: " << inventario[i].codigo << " | " << "Nombre: " << inventario[i].nombre << " | " << "Precio: " << inventario[i].precio << " | " << "Stock: " << inventario[i].stock << endl;
    }
    cout << endl;
}