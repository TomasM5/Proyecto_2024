#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <cstring>
#include <cstdio>
#include "Fecha.h"

class Producto{
    public:
        Producto();

        void Cargar();
        void Mostrar();

        void setID(int val){ _ID = val;}
        void setMarca(const char *val){ strcpy(_Marca, val);}
        void setDescripcion(const char *val){ strcpy(_Descripcion, val);}
        void setCategoria(int val){ _Categoria = val;}
        void setStock(int val){ _Stock  = val;}
        void setValor(float val){ _Valor = val;}
        void setEstado(bool val){ _Estado = val;}
        void setFechaIngreso (Fecha val){_Ingreso = val;}

        int getID(){return _ID;}
        const char *getMarca(){return _Marca;}
        const char *getDescripcion(){return _Descripcion;}
        int getCategoria(){return _Categoria;}
        int getStock(){return _Stock;}
        float getValor(){return _Valor;}
        bool getEstado(){return _Estado;}
        Fecha getFechaIngreso(){return _Ingreso;}

        void registrarProducto();
        void listarProductos();
        void buscarProductoPorID();
        void buscarProductoPorCategoria();
        void buscarProductoPorRangoPrecio();
        void buscarProductoPorFechaIngreso();

        //  TODO
        void ordenarPrecio(Producto *registros,int cantidad, char *orden);
        void ordenarDescripcion(Producto *registros,int cantidad);
        void ordenarCategoria(Producto *registros,int cantidad);
        void ordenarIngreso();


    protected:

    private:
        int _ID;
        char _Marca[20];
        char _Descripcion[50];
        int _Categoria;
        /* CODIGOS DE CATEGORIAS
        1 - Muebles
        2 - Iluminacion
        3 - Cuadros
        4 - Textiles
        5 - Plantas artificiales
        6 - Ceramicas
        7 -
        8 -
        9 -
        */
        int _Stock;
        float _Valor;
        bool _Estado;
        Fecha _Ingreso;

};

class ArchivoProductos {
    private:
        char nombre[30];
    public:
        ArchivoProductos (const char *n){strcpy(nombre, n);};

        Producto Leer_Registro(int pos);
        int Contar_Registro ();
        bool Grabar_Registro(Producto reg);

};

#endif // PRODUCTO_H_INCLUDED
