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
    Cliente *a;
    Cargar();
    a=this;
    file.Grabar_Registro(*a);
    cout << "Cliente registrado exitosamente" << endl;
}   // ver registrarVendedor

void Cliente::listarClientes(){ ///muestra todos los clientes registrados
    Cliente aux;
    ArchivoClientes file="clientes.dat";

    int i=0;
    bool fin=false;
    while(!fin){
        aux=file.Leer_Registro(i);
        if (aux.getEstado()) {
            fin=true;
            break;
        }
        aux.Mostrar();
        cout << endl;
        i++;

    }
}

void Cliente::buscarClientePorID(int id){ ///busca y muestra un cliente por su ID
    ArchivoClientes file="clientes.dat";
    Cliente aux;

    int i=0;
    do{
        aux=file.Leer_Registro(i);
        if(aux.getID() == id){
            aux.Mostrar();
            return;
        }
        i++;
    }while (aux.getEstado()!=0);
    cout << "Cliente no encontrado" << endl;

}

void Cliente::buscarClientePorDNI(int dni){ ///busca y muestra un cliente por su DNI
    ArchivoClientes file="clientes.dat";
    Cliente aux;

    int i=0;
    do{
        aux=file.Leer_Registro(i);
        if(aux.getDNI() == dni){
            aux.Mostrar();
            return;
        }
        i++;
    }while (aux.getEstado()!=0);
    cout << "Cliente no encontrado" << endl;

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

Cliente ArchivoClientes::Leer_Registro(int pos){
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
