#include<iostream>
#include "Venta.h"
using namespace std;

Venta::Venta() {
    _ID = 0;
    _IDvendedor = 0;
    _IDcliente = 0;
    _FormaPago = 0;
    _Envio = false;
}

void Venta::Cargar() {
    cout << "Cargar Venta" << endl;
    cout << "ID: ";
    cin >> _ID;
    _Fecha.Cargar();
    cout << "ID Vendedor: ";
    cin >> _IDvendedor;
    cout << "ID Cliente: ";
    cin >> _IDcliente;
    cout << "Forma de Pago: ";
    cin >> _FormaPago;
    cout << "Envio (1 si, 0 no): ";
    cin >> _Envio;
}

void Venta::Mostrar() {
    cout << "Mostrar Venta" << endl;
    cout << "ID: " << _ID << endl;
    _Fecha.MostrarNumero();
    cout << "ID Vendedor: " << _IDvendedor << endl;
    cout << "ID Cliente: " << _IDcliente << endl;
    cout << "Forma de Pago: " << _FormaPago << endl;
    cout << "Envio: " << (_Envio ? "Si" : "No") << endl;
}
