#include<iostream>
#include "Proveedor.h"
using namespace std;


Proveedor::Proveedor(){
    strcpy(_Empresa, "");
}

void Proveedor::Cargar() {
    cout << "Cargar Proveedor" << endl;
    Persona::Cargar();
    cout << "Empresa: ";
    cin.ignore();
    cin.getline(_Empresa, 30);
}

void Proveedor::Mostrar() {
    cout << "Mostrar Proveedor" << endl;
    Persona::Mostrar();
    cout << "Empresa: " << _Empresa << endl;
}
