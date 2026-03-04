#include <iostream>
#include <fstream>
using namespace std;

/*
Para resolver este ejercicio y cumplir con las exigencias de acceso inmediato sin recorrer todo el archivo,
utilizaremos el acceso aleatorio
*/

//estructura para cada empleado
struct Empleado {
    int id;
    char nombre[30];
    double salario;
};

//prototipo de funcion para acceder al registro
void accederRegistro (const char *nombre_archivo, int id);

int main () {

    //declaramos el nombre del archivo
    char nombre[] = "input/empleados.dat";
    int id;

    //recibimos el ID del empleado
    cout << "Ingrese ID de empleado: "; cin >> id;
    cout << endl;

    //llamamos a la funcion accederRegistro
    accederRegistro(nombre, id);

    return 0;
}

void accederRegistro (const char *nombre_archivo, int id){

    Empleado p;
    
    //creamos un archivo y lo declaramos en escritura, lectura y binario
    fstream archivo(nombre_archivo, ios::in | ios::out | ios::binary);

    //verificamos que se ha abierto correctamente
    if (!archivo){
        cout << "Algo ha salido mal";
        return;
    }


    //nos movemos la cantidad de bytes necesarios desde el inicio para ubicar el id
    //creamos una variable para almacenar la posicion que es de nuestro interes

    int pos = (id - 1)*sizeof(Empleado);

    //trasladamos el puntero de lectura usando ios::beg para garantizar una posicion inicial fija
    archivo.seekg(pos, ios::beg);
    //leemos los datos en binario
    archivo.read(reinterpret_cast<char*>(&p), sizeof(Empleado));

    //mostramos los datos del empleado encontrado
    cout << "--- DATOS DEL EMPLEADO ---\n";
    cout << "ID: " << p.id << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Salario: " << p.salario << endl;
    cout << endl;
      
    //creamos la variable para introducir el nuevo salario
    double nuevo_salario;

    cout << "Ingrese nuevo salario: "; cin >> nuevo_salario;

    p.salario = nuevo_salario;

    //usamos .clear() para resetear el estado (buena practica)
    archivo.clear();

    //desplazamos el puntero de escritura de la misma forma
    archivo.seekp(pos, ios::beg);
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Empleado));

    //usamos .clear() para resetear el estado (buena practica)
    archivo.clear();

    //para verificar la actualizacion apropiada del datos
    archivo.seekg(pos, ios::beg);
    archivo.read(reinterpret_cast<char*>(&p), sizeof(Empleado));

    if (p.salario == nuevo_salario){
        cout << "Salario actualizado correctamente" << endl;
    }

    archivo.close();
  
}