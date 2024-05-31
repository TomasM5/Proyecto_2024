#include<iostream>

using namespace std;

#include "Cliente.h"

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
    cin.ignore();
    cin.getline(_Email, 50);
    cout << "Telefono: ";
    cin.ignore();
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
    //completar

}

void Cliente::Leer_Archivo() {
    //completar
}
