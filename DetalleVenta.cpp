#include<iostream>
#include<cstdio>
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
    return _Monto - CalcularDescuento();
}

float DetalleVenta::CalcularDescuento() {
    return _Monto * (_Descuento / 100);
}

void DetalleVenta::Grabar_Archivo() {
    FILE *file = fopen("detalle_venta.dat", "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    fwrite(this, sizeof(DetalleVenta), 1, file);
    fclose(file);
}

void DetalleVenta::Leer_Archivo() {
    FILE *file = fopen("detalle_venta.dat", "rb");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    while(fread(this, sizeof(DetalleVenta), 1, file)){
        Mostrar();
    }
    fclose(file);
}
