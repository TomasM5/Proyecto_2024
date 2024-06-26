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
    _Venta.Cargar();
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
//    cout << "Mostrar Detalle de Venta\n";
    _Venta.Mostrar();
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

int DetalleVenta::getIDVenta () {
    Venta aux;
    int id;
    aux=getVenta();
    id=aux.getID();

    return id;
}

bool ArchivoDetalle::Grabar_Registro(DetalleVenta reg) {
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return 0;
    }
    int grabado=fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}

DetalleVenta ArchivoDetalle::Leer_Registro(int pos) {
    DetalleVenta reg;
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

int ArchivoDetalle::Contar_Registro() {
    FILE *file=fopen(nombre, "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(DetalleVenta);
}
