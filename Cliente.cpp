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

void Cliente::registrarCliente(){ ///carga un nuevo cliente y lo graba en el archivo
    Cargar();
    Grabar_Archivo();
    cout << "Cliente registrado exitosamente" << endl;
}

void Cliente::listarClientes(){ ///muestra todos los clientes registrados
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    while(fread(this, sizeof(Cliente), 1, file)){
        Mostrar();
    }
    fclose(file);
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

void Cliente::Grabar_Archivo(){
    FILE *file = fopen("clientes.dat", "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo" << endl;
      return;
    }
    fwrite(this, sizeof(Cliente), 1, file);
    fclose(file);
}

void Cliente::Leer_Archivo(){
    FILE *file = fopen("clientes.dat", "rb");
    if(file == NULL){
      cout << "Error al abrir el archivo" << endl;
      return;
    }
    while(fread(this, sizeof(Cliente), 1, file)){
        Mostrar();
    }
    fclose(file);
}
