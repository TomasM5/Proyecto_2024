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

    //  La siguiente seccion modifica el stock del producto indicado.
    //  si no existe el producto en el inventario, ofrece agregarlo. -T
    ArchivoProductos fprod("productos.dat");
    Producto prod;
    int i=0, tam;
    bool fin=false, encontrado=false;
    while (!fin){
        prod=fprod.Leer_Registro(i);

        if (prod.getID()==_ProductoID){
            encontrado=true;
            int stock=prod.getStock() + _Cantidad;
            prod.setStock(stock);

            tam=sizeof(Producto) * (i-1); //    para grabar sobre el elemento encontrado ¿tiene que ir en la misma posicion o antes? -T
            FILE *p;
            p=fopen("productos.dat", "wb");
            fseek(p,tam,0); // desplaza el cursor hasta la posicion del producto actual
            fwrite(&prod, sizeof(prod), 1, p);
            fclose(p);

        }
        if (prod.getID()==0) {
            fin=true;
            break;
        }
        i++;
    }

    if (!encontrado) {
        char opc;
        cout << "Producto no hayado en el inventario, desea agregarlo? (s/n)";
        cin >> opc;
        if (opc=='s'||opc=='S'){
            prod.registrarProducto();
        }
    }
}

void Compra::Mostrar() {
    cout << "Mostrar Compra" << endl;
    cout << "ID del Producto: " << _ProductoID << endl;
    cout << "ID del Proveedor: " << _ProveedorID << endl;
    cout << "Cantidad: " << _Cantidad << endl;
    _Fecha.MostrarNumero();
}
