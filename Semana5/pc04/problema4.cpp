#include <iostream>
#include <cstring>
using namespace std;

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

int main () {


    return 0;
}