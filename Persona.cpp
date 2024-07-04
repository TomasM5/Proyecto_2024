#include<iostream>
using namespace std;
#include "Persona.h"
#include "Cliente.h"

Persona::Persona() {
    _ID = 0;
    strcpy(_Nombre, "");
    strcpy(_Apellido, "");
    _DNI = 0;
}

void Persona::Cargar() {
    ArchivoClientes archiC("clientes.dat");
    int id;

    do {
        cout << "ID: ";
        cin >> id;
        if (archiC.existeID(id)) {
            cout << "El ID ya existe. Ingrese otro ID." << endl;
        } else {
            _ID = id;
            break;
        }
    } while (true);

    cout << "Nombre: ";
    cin.ignore();
    cin.getline(_Nombre, 20);
    cout << "Apellido: ";
    cin.getline(_Apellido, 20);
    cout << "Fecha de Nacimiento: " << endl;
    _Nacimiento.Cargar();
    cout << "DNI: ";
    cin >> _DNI;
}

void Persona::Mostrar() {
    cout << "ID: " << _ID << endl;
    cout << "Nombre: " << _Nombre << endl;
    cout << "Apellido: " << _Apellido << endl;
    cout << "Fecha de Nacimiento: ";
    _Nacimiento.MostrarNumero();
    cout << endl;
    cout << "DNI: " << _DNI << endl;
}
