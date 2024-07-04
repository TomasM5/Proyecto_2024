#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED

#include "Venta.h"

class DetalleVenta {
public:
    DetalleVenta();

    void Cargar();
    void Mostrar();
    float MontoFinal();
    float CalcularDescuento();

    void setVenta(Venta val) { _Venta = val; }
    void setIDproducto(int val) { _IDproducto = val; }
    void setCantidad(int val) { _Cantidad = val; }
    void setMonto(float val) { _Monto = val; }
    void setDescuento(float val) { _Descuento = val; }

    int getIDVenta();
    Venta getVenta() { return _Venta; }
    int getIDproducto() { return _IDproducto; }
    int getCantidad() { return _Cantidad; }
    float getMonto() { return _Monto; }
    float getDescuento() { return _Descuento; }

protected:

private:
    Venta _Venta;
    int _IDproducto;
    int _Cantidad;
    float _Monto;
    float _Descuento;
};

class ArchivoDetalle{
    private:
        char nombre[30];
    public:
        ArchivoDetalle(const char *n){strcpy(nombre, n);};

        DetalleVenta Leer_Registro(int pos);
        int Contar_Registro ();
        bool Grabar_Registro(DetalleVenta reg);
        bool borrarContenidoArchivo();
        void Copia_Seguridad();
        void Restaurar();

        void listarRecaudacionAnual();
        void listarRecaudacionMensual();
        void listarRecaudacionPorCliente();
        void listarRecaudacionPorProducto();
        void listarProductosPorCategoria();
};

#endif // DETALLEVENTA_H_INCLUDED
