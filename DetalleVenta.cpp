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
    /*Venta aux;
    int id;
    aux=getVenta();
    id=aux.getID();
    return id;*/
    return _Venta.getID();
}

bool ArchivoDetalle::Grabar_Registro(DetalleVenta reg) {
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return 0;
    }
    bool grabado = fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}

DetalleVenta ArchivoDetalle::Leer_Registro(int pos) {
    DetalleVenta reg;
    FILE *file = fopen(nombre, "rb");
    if(file==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return reg;
    }
    fseek(file, sizeof(reg) * pos, SEEK_SET);
    fread(&reg, sizeof(reg), 1, file);
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

void ArchivoDetalle::Copia_Seguridad(){
    DetalleVenta reg;
    FILE *copia=fopen("copia_seguridad_detalle.dat", "wb");

    int cantidad=Contar_Registro();

    for (int i=0; i<cantidad; i++) {
        reg=Leer_Registro(i);
        fwrite(&reg, sizeof(reg), 1, copia);
    }
    fclose (copia);
    cout << "Copia de seguridad realizada exitosamente." << endl;

}

void ArchivoDetalle::Restaurar(){
    DetalleVenta reg;
    ArchivoDetalle copia("copia_seguridad_detalle.dat");
    int cant=copia.Contar_Registro();

    for(int i=0; i<cant; i++){
        reg=copia.Leer_Registro(i);
        Grabar_Registro(reg);
    }

    cout << "Copia de seguridad restaurada exitosamente." << endl;
}

bool ArchivoDetalle::borrarContenidoArchivo() {
    FILE *file = fopen(nombre, "wb");
    if (file == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    fclose(file);
    cout << "Contenido del archivo borrado exitosamente." << endl;
    return true;
}
