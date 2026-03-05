#include <iostream>
#include <cstring> //para strlen
using namespace std;

/*
Una empresa desea registrar pedidos realizados por clientes. Se definen las estructuras Item y Pedido
Implementar:
Pedido *crearPedido (int numero, const char * cliente, int cantidadItems);
    Reserva memoria dinamica para un pedido
    Reserva memoria para nombreCliente
    Reserva un arreglo dinamico de Item
    Inicializa los Item llamando a Item crearItem (const char *descripcion, int cantidad, double precio);
double calcularTotal (const Pedido *p);
    Total = sum (cantidad*precioUnitario)
Item * itemMasCaro (Pedido *p);
    retorna un puntero al item con mayor precio unitario
void liberarPedido (Pedido *p);
*/

struct Item {
    char *descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido {
    int numeroPedido;
    char *nombreCliente;
    Item *items;
    int cantidadItems;
};

Item crearItem (const char *descripcion, int cantidad, double precio);
Pedido *crearPedido (int numero, const char * cliente, int cantidadItems);
double calcularTotal (const Pedido *p);
Item * itemMasCaro (Pedido *p);
void liberarPedido (Pedido *p);
void mostrarPedido (Pedido *p);

int main () {

    Pedido *inicial = crearPedido(101, "Carlos Perez", 3);
    mostrarPedido (inicial);

    double total = calcularTotal (inicial);
    cout << "Total: " << total << "\n";

    Item *mas_caro = itemMasCaro (inicial);
    
    cout << "Item mas caro: " << mas_caro->descripcion << " | " << "Precio: " << mas_caro->precioUnitario << endl;
    liberarPedido (inicial);


    return 0;
}

Item crearItem (const char *descripcion, int cantidad, double precio){
    int len = strlen(descripcion);
    Item elemento;

    elemento.descripcion = new char [len + 1];

    for (int i = 0; i < len; i++){
        elemento.descripcion[i] = descripcion[i];
    }

    elemento.descripcion[len] = '\0';
    elemento.cantidad = cantidad;
    elemento.precioUnitario = precio;

    return elemento;

}

Pedido *crearPedido (int numero, const char * cliente, int cantidadItems){
    Pedido *pedido = new Pedido;
    pedido->numeroPedido = numero;

    int len = strlen(cliente);
    pedido->nombreCliente = new char [len + 1];
    pedido->items = new Item [cantidadItems];

    for (int i = 0; i < cantidadItems; i++){
        char descripcion[100];
        int cantidad;
        double precio;
        cout << "Ingrese la descripcion del item " << i + 1 << ": "; cin.getline(descripcion, 100);
        cout << "Ingrese la cantidad disponible del producto " << i + 1 << ": "; cin >> cantidad;
        cout << "Ingrese el precio unitario del item " << i + 1 << ": "; cin >> precio;
        pedido->items[i] = crearItem (descripcion, cantidad, precio);
        cin.ignore();
    }

    pedido->cantidadItems = cantidadItems;

    return pedido;

}

double calcularTotal (const Pedido *p){

    double total = 0.0;

    for (int i = 0; i < p->cantidadItems; i++){
        total += (p->items[i].cantidad)*(p->items[i].precioUnitario);
    }

    return total;
}

Item * itemMasCaro (Pedido *p){
    int item_precio = 0;

    for (int i = 0; i < p->cantidadItems; i++){
        if (p->items[i].precioUnitario > p->items[item_precio].precioUnitario){
            item_precio = i;
        }
    }

    return &p->items[item_precio];
}

void liberarPedido (Pedido *p){
    for (int i = 0; i < p->cantidadItems; i++){
        delete [] p->items[i].descripcion;
        p->items[i].descripcion = nullptr;
    }

    delete [] p->nombreCliente;
    p->nombreCliente = nullptr;
    delete [] p->items;
    p->items = nullptr;

    delete p;
    p = nullptr;
}

void mostrarPedido (Pedido *p){
    cout << "Items:\n";
    for (int i = 0; i < p->cantidadItems; i++){
        cout << "- " << p->items[i].descripcion << " | " << "Cant: " << p->items[i].cantidad << " | " << "Precio: " << p->items[i].precioUnitario << endl;
    }
    cout << endl;
}