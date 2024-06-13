#include<iostream>
#include<cstdio>
#include<cstring>
#include "Cliente.h"
using namespace std;


Cliente::Cliente(){
    strcpy(_Domicilio, "");
    strcpy(_Email, "");
    strcpy(_Telefono, "");
    _Banco = 0;
}

void Cliente::Cargar() {
    cout << "Cargar Cliente" << endl;
    Persona::Cargar();
    cout << "Domicilio: ";
    cin.ignore();
    cin.getline(_Domicilio, 50);
    cout << "Correo: ";
    cin.getline(_Email, 50);
    cout << "Telefono: ";
    cin.getline(_Telefono, 15);
    cout << "Banco: ";
    cin >> _Banco;
}

void Cliente::Mostrar() {
    cout << "Mostrar Cliente" << endl;
    Persona::Mostrar();
    cout << "Domicilio: " << _Domicilio << endl;
    cout << "Correo: " << _Email << endl;
    cout << "Telefono: " << _Telefono << endl;
    cout << "Banco: " << _Banco << endl;
}

void registrarCliente(Cliente reg, ArchivoClientes file){ ///carga un nuevo cliente y lo graba en el archivo
    reg.Cargar();
    file.Grabar_Registro(reg);
    cout << "Cliente registrado exitosamente" << endl;
}

void listarClientes(ArchivoClientes file){ ///muestra todos los clientes registrados
    Cliente aux;
    int i=0;
    while(aux=file.Leer_Registro(i)){ //    FIX
        aux.Mostrar();
        cout << endl;
        i++;
    }
}

void Cliente::buscarClientePorID(int id){ ///busca y muestra un cliente por su ID
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    while(fread(this, sizeof(Cliente), 1, file)){
        if(this->getID() == id) {
            Mostrar();
            fclose(file);
            return;
        }
    }
    cout << "Cliente no encontrado" << endl;
    fclose(file);
}

void Cliente::buscarClientePorDNI(int dni){ ///busca y muestra un cliente por su DNI
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while(fread(this, sizeof(Cliente), 1, file)){
        if(this->getDNI() == dni){
            Mostrar();
            fclose(file);
            return;
        }
    }
    cout << "Cliente no encontrado" << endl;
    fclose(file);
}

void Cliente::buscarClientePorNombre(const char* nombre){ ///busca y muestra un cliente por su nombre
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    while(fread(this, sizeof(Cliente), 1, file)) {
        if(strcmp(this->getNombre(), nombre) == 0) {
            Mostrar();
            fclose(file);
            return;
        }
    }
    cout << "Cliente no encontrado" << endl;
    fclose(file);
}

int ArchivoClientes::Contar_Registro() {
    FILE *file=fopen(nombre, "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(Cliente);
}

Producto ArchivoClientes::Leer_Registro(int pos){
    Cliente reg;
    FILE *file;
    file=fopen(nombre, "rb");
    if(file==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return reg;
    }
    fseek(file, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, file);
    fclose(file);
    return reg;
}

bool ArchivoClientes::Grabar_Registro(Cliente reg){
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return false;
    }
    int grabado=fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}
