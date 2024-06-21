#include<iostream>
#include<cstdio>
#include "Proveedor.h"
using namespace std;


Proveedor::Proveedor(){
    strcpy(_Empresa, "");
}

void Proveedor::Cargar(){
    cout << "Cargar Proveedor" << endl;
    Persona::Cargar();
    cout << "Empresa: ";
    cin.ignore();
    cin.getline(_Empresa, 30);
}

void Proveedor::Mostrar(){
    cout << "Mostrar Proveedor" << endl;
    Persona::Mostrar();
    cout << "Empresa: " << _Empresa << endl;
}

void Proveedor::registrarProveedor(){ ///carga un nuevo proveedor y lo registra en el archivo
    Cargar();
    FILE *file = fopen("proveedores.dat", "ab");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fwrite(this, sizeof(Proveedor), 1, file);
    fclose(file);
    cout << "Proveedor registrado con exito" << endl;
}

void Proveedor::listarProveedores(){///muestra todos los proveedores registrados
    FILE *file = fopen("proveedores.dat", "rb");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Proveedor proveedor;
    int i=0;
    while(fread(&proveedor, sizeof(Proveedor), 1, file)){
        proveedor.Mostrar();
        cout << endl;
        fseek(file, sizeof(Proveedor)*i,0);
        i++;
    }
    fclose(file);
}

void Proveedor::buscarProveedor(){///busca y muestra un proveedor por su ID
    int id;
    cout << "Ingrese el ID del proveedor: ";
    cin >> id;

    FILE *file = fopen("proveedores.dat", "rb");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Proveedor proveedor;
    bool encontrado = false;
    while(fread(&proveedor, sizeof(Proveedor), 1, file)){
        if(proveedor.getID() == id){
            proveedor.Mostrar();
            encontrado = true;
            break;
        }
    }
    fclose(file);
}

/**
hay que implementar una nueva clase llamada Compras

void Proveedor::comprasPorProveedor(){
    int id;
    cout << "Ingrese el ID del proveedor: ";
    cin >> id;

    FILE *file = fopen("compras.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Compra compra;
    bool encontrado = false;
    while(fread(&compra, sizeof(Compra), 1, file)){
        if(compra.getProveedorID() == id){
            compra.Mostrar();
            encontrado = true;
        }
    }
    if(!encontrado){
        cout << "No se encontraron compras para este proveedor" << endl;
    }
    fclose(file);
}
**/
