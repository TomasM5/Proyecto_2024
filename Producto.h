#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <cstring>

class Producto{
    public:
        Producto();

        void Cargar();
        void Mostrar();
        void Grabar_Archivo();
        void Leer_Archivo();

        void setID(int val){ _ID = val;}
        void setMarca(const char *val){ strcpy(_Marca, val;)}
        void setDescripcion(const char *val){ strcpy(_Descripcion, val;)}
        void setCategoria(int val){ _Categoria = val;}
        void setStock(int val){ _Stock  = val;}
        void setValor(float val){ _Valor = val;}
        void setEstado(bool val){ _Estado = val;}

        int getID(){return _ID;}
        const char *getMarca(){return _Marca;}
        const char *getDescripcion(){return _Descripcion;}
        int getCategoria(){return _Categoria;}
        int getStock(){return _Stock;}
        float getValor(){return _Valor;}
        bool getEstado(){return _Estado;}


    protected:

    private:
        int _ID;
        char _Marca[20];
        char _Descripcion[50];
        int _Categoria;
        int _Stock;
        float _Valor;
        bool _Estado;

};

#endif // PRODUCTO_H_INCLUDED
