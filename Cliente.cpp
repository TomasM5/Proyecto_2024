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
    _Estado=false;
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
    setEstado(true);
}

void Cliente::Mostrar() {
    cout << "Mostrar Cliente" << endl;
    Persona::Mostrar();
    cout << "Domicilio: " << _Domicilio << endl;
    cout << "Correo: " << _Email << endl;
    cout << "Telefono: " << _Telefono << endl;
    cout << "Banco: " << _Banco << endl;
}

void Cliente::registrarCliente(){///carga un nuevo cliente y lo graba en el archivo
    ArchivoClientes file="clientes.dat";
    Cargar();
    file.Grabar_Registro(*this);
    cout << "Cliente registrado exitosamente" << endl;
}   // ver registrarVendedor

void Cliente::listarClientes(){ ///muestra todos los clientes registrados
    Cliente aux;
    ArchivoClientes file("clientes.dat");
    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i++){
        aux = file.Leer_Registro(i);
        if(aux.getEstado()){
            aux.Mostrar();
            cout << endl;
        }
    }
}

void Cliente::buscarClientePorID(){ ///busca y muestra un cliente por su ID
    ArchivoClientes file("clientes.dat");
    Cliente reg;

    bool encontrado = false;
    int id;
    cout << "Ingrese ID del cliente: ";
    cin >> id;

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        reg = file.Leer_Registro(i);
        if(reg.getID() == id && reg.getEstado()){
            encontrado = true;
            reg.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "Cliente no encontrado" << endl;
    }
}

void Cliente::buscarClientePorDNI(){ ///busca y muestra un cliente por su DNI
    ArchivoClientes file("clientes.dat");
    Cliente reg;

    bool encontrado = false;
    int dni;
        cout << "Ingrese DNI del cliente: ";
        cin >> dni;

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        reg = file.Leer_Registro(i);
        if(reg.getDNI() == dni && reg.getEstado()){
            encontrado = true;
            reg.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "Cliente no encontrado" << endl;
    }

}

void Cliente::buscarClientePorNombre(){ ///busca y muestra un cliente por su nombre
    ArchivoClientes file("clientes.dat");
    Cliente reg;

    bool encontrado = false;
    char nombre[50];
    cout << "Ingrese nombre del cliente: ";
    cin.ignore();
    cin.getline(nombre, 50);

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        reg = file.Leer_Registro(i);
        if(strcmp(reg.getNombre(), nombre) == 0 && reg.getEstado()){
            encontrado = true;
            reg.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "Cliente no encontrado" << endl;
    }
}

int ArchivoClientes::Contar_Registro() {
    FILE *file=fopen(nombre, "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(Cliente);
}

Cliente ArchivoClientes::Leer_Registro(int pos){
    Cliente reg;
    FILE *file;
    file=fopen(nombre, "rb");
    if(file==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return reg;
    }
    fseek(file, sizeof(Cliente) * pos, 0);
    fread(&reg, sizeof(Cliente), 1, file);
    fclose(file);
    return reg;
}

bool ArchivoClientes::Grabar_Registro(Cliente reg){
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return false;
    }
    int grabado = fwrite(&reg, sizeof(Cliente), 1, file);
    fclose(file);
    return grabado == 1;
}

void ArchivoClientes::Copia_Seguridad(){
    Cliente reg;
    FILE *copia=fopen("copia_seguridad_clientes.dat", "wb");

    int cantidad=Contar_Registro();

    for (int i=0; i<cantidad; i++) {
        reg=Leer_Registro(i);
        fwrite(&reg, sizeof(reg), 1, copia);
    }
    fclose (copia);
    cout << "Copia de seguridad realizada exitosamente." << endl;

}

void ArchivoClientes::Restaurar(){
    Cliente reg;
    ArchivoClientes copia("copia_seguridad_clientes.dat");
    int cant=copia.Contar_Registro();

    for(int i=0; i<cant; i++){
        reg=copia.Leer_Registro(i);
        Grabar_Registro(reg);
    }

    cout << "Copia de seguridad restaurada exitosamente." << endl;
}

bool ArchivoClientes::existeID(int id) {
    int cantReg = Contar_Registro();
    for (int i = 0; i < cantReg; i++) {
        Cliente cliente = Leer_Registro(i);
        if (cliente.getID() == id) {
            return true;
        }
    }
    return false;
}

bool ArchivoClientes::borrarContenidoArchivo(){
    FILE *file = fopen(nombre, "wb");
    if (file == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    fclose(file);
    cout << "Contenido del archivo borrado exitosamente." << endl;
    return true;
}
