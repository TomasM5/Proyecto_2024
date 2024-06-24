#include <iostream>
#include <cstring>
#include "Compra.h"
#include "Producto.h"

using namespace std;

Compra::Compra() {
    _ProductoID = 0;
    _ProveedorID = 0;
    _Cantidad = 0;
}

void Compra::Cargar() {
    cout << "Cargar Compra" << endl;
    cout << "ID del Producto: ";
    cin >> _ProductoID;
    cout << "ID del Proveedor: ";
    cin >> _ProveedorID;
    cout << "Cantidad: ";
    cin >> _Cantidad;
    _Fecha.Hoy();

    ///TODO-> buscar o agregar producto/actualizar stock
}

void Compra::Mostrar() {
    cout << "Mostrar Compra" << endl;
    cout << "ID del Producto: " << _ProductoID << endl;
    cout << "ID del Proveedor: " << _ProveedorID << endl;
    cout << "Cantidad: " << _Cantidad << endl;
    _Fecha.MostrarNumero();
}
