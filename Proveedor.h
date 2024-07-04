#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

#include "Persona.h"

class Proveedor : public Persona{
    public:
        Proveedor();

        void Cargar();
        void Mostrar();

        void setEmpresa(const char *var){ strcpy(_Empresa, var);}
        const char *getEmpresa(){ return _Empresa;}

        void registrarProveedor();
        void listarProveedores();
        void buscarProveedor();
        void comprasPorProveedor();
        Proveedor Leer_Registro(int pos);
        int Contar_Registro();
        void Copia_Seguridad();
        void Restaurar();

    protected:

    private:
        char _Empresa[30];
};

#endif // PROVEEDOR_H_INCLUDED
