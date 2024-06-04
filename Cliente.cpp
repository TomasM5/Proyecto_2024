#include<iostream>
#include<cstdio>
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

void Cliente::Grabar_Archivo() {
    FILE *file = fopen("clientes.dat", "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    fwrite(this, sizeof(Cliente), 1, file);
    fclose(file);
}

void Cliente::Leer_Archivo() {
    FILE *file = fopen("cliente.dat", "rb");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    while(fread(this, sizeof(Cliente), 1, file)){
        Mostrar();
    }
    fclose(file);
}
