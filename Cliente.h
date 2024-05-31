#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <cstring>
#include "stdio.h"
#include "Persona.h"

class Cliente : public Persona{
    public:
        Cliente();

        void Cargar();
        void Mostrar();
        void Grabar_Archivo();
        void Leer_Archivo();

        void setDomicilio(char val) { strcpy(_Domicilio, val;) }
        void setCorreo(char val) { strcpy(_Email, val;) }
        void setTelefono(char val) { strcpy(_Telefono, val;) }
        void setBanco(int val) { _Banco = val; }
        const char *geDomicilio() { return _Domicilio; }
        const char *getCorreo() { return _Email; }
        const char *getTelefono() { return _Telefono; }
        int getBanco() { return _Banco; }

    protected:

    private:
        char _Domicilio[50];
        char _Email[50];
        char _Telefono[15];
        int _Banco;
};

#endif // CLIENTE_H_INCLUDED
