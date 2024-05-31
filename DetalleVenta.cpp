#include<iostream>
#include "DetalleVenta.h"
using namespace std;

DetalleVenta::DetalleVenta() {
    _IDproducto = 0;
    _Cantidad = 0;
    _Monto = 0.0;
    _Descuento = 0.0;
}

void DetalleVenta::Cargar() {
    cout << "Cargar Detalle de Venta" << endl;
    cout << "ID Producto: ";
    cin >> _IDproducto;
    cout << "Cantidad: ";
    cin >> _Cantidad;
    cout << "Monto: ";
    cin >> _Monto;
    cout << "Descuento: "; ///revisar tipos de descuentos:
    cin >> _Descuento;     ///banco, metodo de pago (efectivo), etc.
}

void DetalleVenta::Mostrar() {
    cout << "Mostrar Detalle de Venta\n";
    cout << "ID Producto: " << _IDproducto << endl;
    cout << "Cantidad: " << _Cantidad << endl;
    cout << "Monto: " << _Monto << endl;
    cout << "Descuento: " << _Descuento << endl;
}

float DetalleVenta::MontoFinal() {
    //completar
}

float DetalleVenta::CalcularDescuento() {
    //completar
}

void DetalleVenta::Grabar_Archivo() {
    //completar
}

void DetalleVenta::Leer_Archivo() {
    //completar
}
