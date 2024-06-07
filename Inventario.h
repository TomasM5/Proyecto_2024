#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED

#include "Producto.h"
#include <vector>

class Inventario {
public:
    void mostrarInventario();
    void buscarProducto();
    void nuevoProducto();
    void compraStock();

protected:

private:
    std::vector<Producto> productos;
};

#endif // INVENTARIO_H_INCLUDED
