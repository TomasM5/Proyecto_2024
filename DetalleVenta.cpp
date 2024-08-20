#include<iostream>
#include<cstdio>
#include "DetalleVenta.h"
#include "Producto.h"
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
    Venta v;
    FILE *copiadet=fopen("copia_seguridad_detalle.dat", "wb");
    FILE *copiaven=fopen("copia_seguridad_ventas.dat", "wb");

    int cantidad=Contar_Registro();

    for (int i=0; i<cantidad; i++) {
        reg=Leer_Registro(i);
        v=reg.getVenta();
        fwrite(&reg, sizeof(reg), 1, copiadet);
        fwrite(&v, sizeof(v), 1, copiaven);
    }
    fclose (copiadet);
    fclose (copiaven);
    cout << "Copia de seguridad realizada exitosamente." << endl;

}

void ArchivoDetalle::Restaurar(){
    DetalleVenta reg;
    Venta v;
    ArchivoDetalle copia("copia_seguridad_detalle.dat");
    ArchivoVentas copiaven("copia_seguridad_ventas.dat");
    ArchivoVentas ven("ventas.dat");
    int cant=copia.Contar_Registro();

    for(int i=0; i<cant; i++){
        reg=copia.Leer_Registro(i);
        v=copiaven.Leer_Registro(i);
        ven.Grabar_Registro(v);
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

void ArchivoDetalle::listarRecaudacionAnual() {
    float recaudacionTotal = 0.0;
    DetalleVenta detalle;
    ArchivoDetalle fdet("detalle_ventas.dat");

    bool encontrado = false;
    int anio;
    cout << "Ingrese el anio: ";
    cin >> anio;

    int cantReg = fdet.Contar_Registro();

    for (int i = 0; i < cantReg; i++) {
        detalle = fdet.Leer_Registro(i);
        if (detalle.getVenta().getFecha().getAnio() == anio) {
            encontrado = true;
            recaudacionTotal += detalle.getMonto();
        }
    }
    if(encontrado){
        cout << "Recaudacion total del anio " << anio << ": $" << recaudacionTotal << endl;
    }
    else{
        cout << "no se registran recaudacion para la fecha seleccionada" << endl;
    }

}

void ArchivoDetalle::listarRecaudacionMensual() {
    float recaudacionTotal = 0.0;
    DetalleVenta detalle;
    ArchivoDetalle fdet("detalle_ventas.dat");

    bool encontrado = false;
    int mes, anio;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    int cantReg = fdet.Contar_Registro();

    for (int i = 0; i < cantReg; i++) {
        detalle = fdet.Leer_Registro(i);
        if (detalle.getVenta().getFecha().getMes() == mes && detalle.getVenta().getFecha().getAnio() == anio) {
            encontrado = true;
            recaudacionTotal += detalle.getMonto();
        }
    }
    if(encontrado){
        cout << "Recaudacion total del mes " << mes << "/" << anio << ": $" << recaudacionTotal << endl;
    }
    else{
        cout << "no se registran recaudacion para la fecha seleccionada" << endl;
    }
}

void ArchivoDetalle::listarRecaudacionPorCliente() {
    float recaudacionTotal = 0.0;
    DetalleVenta detalle;
    ArchivoDetalle fdet("detalle_ventas.dat");

    bool encontrado = false;
    int IDcliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> IDcliente;

    int cantReg = fdet.Contar_Registro();

    for (int i = 0; i < cantReg; i++) {
        detalle = fdet.Leer_Registro(i);
        if(detalle.getVenta().getIDcliente() == IDcliente){
            encontrado = true;
            recaudacionTotal += detalle.getMonto();
        }
    }
    if(encontrado){
        cout << "Recaudacion total del cliente " << IDcliente <<": $" << recaudacionTotal << endl;
    }
    else{
        cout << "no se encontro cliente con ese ID" << endl;
    }
}

void ArchivoDetalle::listarRecaudacionPorProducto() {
    float recaudacionTotal = 0.0;
    DetalleVenta detalle;
    ArchivoDetalle fdet("detalle_ventas.dat");

    bool encontrado = false;
    int IDproducto;
    cout << "Ingrese el ID del producto: ";
    cin >> IDproducto;

    int cantReg = fdet.Contar_Registro();

    for (int i = 0; i < cantReg; i++) {
        detalle = fdet.Leer_Registro(i);
        if (detalle.getIDproducto() == IDproducto) {
            encontrado = true;
            recaudacionTotal += detalle.getMonto();
        }
    }
    if(encontrado){
        cout << "Recaudacion total del producto " << IDproducto << ": $" << recaudacionTotal << endl;
    }
    else{
        cout << "no se encontro producto con ese ID" << endl;
    }

}

void ArchivoDetalle::listarProductosPorCategoria() {
    Producto prod;
    ArchivoProductos pdet("productos.dat");

    bool encontrado = false;
    int categoria;
    cout << "Ingrese la categoria: ";
    cin >> categoria;

    int cantReg = pdet.Contar_Registro();

    int fila=20;
    for (int i = 0; i < cantReg; i++) {
        prod = pdet.Leer_Registro(i);
        if (prod.getCategoria() == categoria) {
            encontrado = true;
            prod.Mostrar(fila);
            fila++;
            cout << endl;
        }
    }
    if(!encontrado) cout << "no se encontro producto con esa categoria" << endl;
}

