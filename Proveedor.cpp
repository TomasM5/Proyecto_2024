#include<iostream>
#include<cstdio>
#include "Proveedor.h"
#include "Compra.h"
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

Proveedor Proveedor::Leer_Registro(int pos) {
    Proveedor reg;
    FILE *file=fopen("proveedores.dat", "rb");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return reg;
    }
    fseek(file, pos * sizeof(Proveedor), SEEK_SET);
    fread(&reg, sizeof(Proveedor), 1, file);
    fclose(file);
    return reg;
}

int Proveedor::Contar_Registro() {
    FILE *file=fopen("proveedores.dat", "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(Proveedor);
}

void Proveedor::Copia_Seguridad(){
    FILE *copia=fopen("copia_seguridad_proveedores.dat", "wb");
    Proveedor reg;
    int cant=Contar_Registro();


    int cantidad=Contar_Registro();

    for (int i=0; i<cantidad; i++) {
        reg=Leer_Registro(i);
        fwrite(&reg, sizeof(reg), 1, copia);
    }
    fclose (copia);
    cout << "Copia de seguridad realizada exitosamente." << endl;
}

void Proveedor::Restaurar(){
    FILE *file=fopen("copia_seguridad_proveedores.dat", "rb");
    if (file==NULL) {return;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    int cantidad=tam/sizeof(Proveedor);
    fseek(file,0,0);

    Proveedor reg;
    FILE *p=fopen("proveedores.dat", "ab");

    for (int i=0; i<cantidad; i++) {
        fseek(file, i * sizeof(Proveedor), SEEK_SET);
        fread(&reg, sizeof(Proveedor), 1, file);
        fwrite(&reg, sizeof(reg), 1, p);
    }
    cout << "Copia de seguridad restaurada exitosamente." << endl;

    fclose(file);
    fclose(p);
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
