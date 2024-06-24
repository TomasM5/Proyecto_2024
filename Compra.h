#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

#include "Fecha.h"

class Compra {
private:
    int _ProductoID;
    int _ProveedorID;
    int _Cantidad;
    Fecha _Fecha;

public:
    Compra();
    void Cargar();
    void Mostrar();

    int getProductoID() { return _ProductoID; }
    int getProveedorID() { return _ProveedorID; }
    int getCantidad() { return _Cantidad; }
    Fecha getFecha() { return _Fecha; }
};

#endif // COMPRA_H_INCLUDED
