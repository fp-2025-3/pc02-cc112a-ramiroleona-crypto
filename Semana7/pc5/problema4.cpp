#include <iostream>
#include <fstream>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main () {

    fstream entrada("input/ventas.dat", ios::in | ios::binary);
    ofstream salida("output/reporte_problema4.txt");

    if (!entrada || !salida){
        cout << "Algo ha salido mal";
        return 1;
    }

    //dato para lectura
    Venta p;

    //para obtener el total de registros y monto
    int cant_registros = 0;
    double monto_total = 0.0;

    //para los vendedores
    int num_vendedores = 0;
    double *recaudaciones = nullptr;
    int *idVendedores = nullptr;

    //para los productos
    int num_productos = 0;
    int *cantidades_productos = nullptr;
    int *idProductos = nullptr;
    
    //para las ventas sospechosas
    int num_sospechosas = 0;
    Venta *sospechosas = nullptr;

    //Usamos nullptr para que los casos se construyan poco a poco y facilitar el redimensionar los arreglos
    
    while (entrada.read(reinterpret_cast<char*>(&p), sizeof(Venta))){
        
        //inicializamo un booleano que permitira verificar si el elemento esta repetido
        bool encontrado = false;

        for (int i = 0; i < num_vendedores; i++){
            //si encontramos que el id del vendedor ya esta registrado, hacemos encontrado verdadero y acumulamos la recaudacion en el arreglo paralelo
            if (*(idVendedores+i) == p.idVendedor){
                *(recaudaciones + i) += p.cantidad * p.precioUnitario;
                encontrado = true;
                break;
            }
        }

        //si no se encontro la id, corresponde redimensionar 
        if (!encontrado){
            int *id_vendedor_temporal = new int [num_vendedores + 1];
            double *recaudacion_temporal = new double [num_vendedores + 1];

            //copiamos los datos actuales
            for (int i = 0; i < num_vendedores; i++){
                *(id_vendedor_temporal + i) = *(idVendedores + i);
                *(recaudacion_temporal + i) = *(recaudaciones + i);
            }

            //aniadimos manualmente la nueva id y su primera recaudacion para evitar tener recaudaciones no inicializadas
            *(id_vendedor_temporal + num_vendedores) = p.idVendedor;
            *(recaudacion_temporal + num_vendedores) = p.cantidad * p.precioUnitario;

            //borramos los datos anteriores
            delete [] idVendedores;
            delete [] recaudaciones;

            //reasignamos a los punteros
            idVendedores = id_vendedor_temporal;
            recaudaciones = recaudacion_temporal;

            num_vendedores++;
        }

        //convertimos el encontrado a nulo nuevamente para analiar los productos

        encontrado = false;

        for (int i = 0; i < num_productos; i++){
            //buscamos el id del producto
            if (*(idProductos + i) == p.idProducto){
                *(cantidades_productos + i) += p.cantidad;
                encontrado = true;
                break;
            }
        }

        if (!encontrado){
            int *id_producto_temporal = new int [num_productos + 1];
            int *cantidades_productos_temporal = new int [num_productos + 1];

            //copiamos datos
            for (int i = 0; i < num_productos; i++){
                *(id_producto_temporal + i) = *(idProductos + i);
                *(cantidades_productos_temporal + i) = *(cantidades_productos + i);
            }

            //adicion del nuevo producto
            *(id_producto_temporal + num_productos) = p.idProducto;
            *(cantidades_productos_temporal + num_productos) = p.cantidad;

            //borramos y actualizamos
            delete [] idProductos;
            delete [] cantidades_productos;

            idProductos = id_producto_temporal;
            cantidades_productos = cantidades_productos_temporal;

            num_productos++;
        }

        //finalmente, ubicamos las ventas sospechosas

        if (p.cantidad > 100){
            Venta *sospechosas_temporal = new Venta [num_sospechosas + 1];

            //redimensionamos usando el arreglo temporal
            for (int i = 0; i < num_sospechosas; i++){
                *(sospechosas_temporal + i) = *(sospechosas + i);
            }

            *(sospechosas_temporal + num_sospechosas) = p;

            delete [] sospechosas;

            sospechosas = sospechosas_temporal;

            num_sospechosas++;
        }

        //para el monto total
        cant_registros++;
        monto_total += p.cantidad * p.precioUnitario;
    }

    //Ya con los arreglos creados, podemos ubicar al vendedor con mayor recaudacion y el producto mas vendido
    int idVendedor_maximo = -1;
    double recaudacion_maxima = 0.0;
    int idProducto_mayor = -1;
    int cantidad_producto_mayor = 0;

    for (int i = 0; i < num_vendedores; i++){
        if (*(recaudaciones + i) > recaudacion_maxima){
            recaudacion_maxima = *(recaudaciones + i);
            idVendedor_maximo = *(idVendedores + i);
        }
    }

    for (int i = 0; i < num_productos; i++){
        if (*(cantidades_productos + i) > cantidad_producto_mayor){
            cantidad_producto_mayor = *(cantidades_productos + i);
            idProducto_mayor = *(idProductos + i);
        }
    }

    salida << "--- REPORTE GENERAL DE VENTAS ---\n";
    salida << endl;
    salida << "Total de registros: " << cant_registros << "\n";
    salida << endl;
    salida << "MONTO TOTAL VENDIDO:\n";
    salida << "S/. " << monto_total << "\n";
    salida << endl;
    salida << "---------------------------------------\n";
    salida << "VENDEDOR CON MAYOR RECAUDACION:\n";
    salida << "ID Vendedor: " << idVendedor_maximo << "\n";
    salida << "Total vendido: S/. " << recaudacion_maxima << "\n";
    salida << endl;
    salida << "---------------------------------------\n";
    salida << "PRODUCTO MAS VENDIDO:\n";
    salida << "ID Producto: " << idProducto_mayor << "\n";
    salida << "Total unidades: " << cantidad_producto_mayor << "\n";
    salida << endl;
    salida << "---------------------------------------\n";
    salida << "VENTAS SOSPECHOSAS (cantidad > 100):\n";
    salida << endl;

    for (int i = 0; i < num_sospechosas; i++){
        salida << "ID Venta: " << (*(sospechosas + i)).idVenta << " | Vendedor: " << (*(sospechosas + i)).idVendedor << " | Producto: " << (*(sospechosas + i)).idProducto << " | Cantidad: " << (*(sospechosas + i)).cantidad << endl;
    }

    delete [] recaudaciones;
    delete [] idVendedores;
    delete [] cantidades_productos;
    delete [] idProductos;
    delete [] sospechosas;

    recaudaciones = nullptr;
    idVendedores = nullptr;
    cantidades_productos = nullptr;
    idProductos = nullptr;
    sospechosas = nullptr;

    return 0;
}
