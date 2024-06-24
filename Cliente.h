#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <cstring>
#include <cstdio>
#include "Persona.h"

class Cliente : public Persona{
    public:
        Cliente();

        void Cargar();
        void Mostrar();
        void setDomicilio(const char* val) { strcpy(_Domicilio, val); }
        void setCorreo(const char* val) { strcpy(_Email, val); }
        void setTelefono(const char* val) { strcpy(_Telefono, val); }
        void setBanco(int val) { _Banco = val; }
        void setEstado(bool val) { _Estado= val; }

        const char* getDomicilio() { return _Domicilio; }
        const char* getCorreo() { return _Email; }
        const char* getTelefono() { return _Telefono; }
        int getBanco() { return _Banco; }
        bool getEstado() { return _Estado; }

        void registrarCliente();
        void listarClientes();
        void buscarClientePorID(int id);
        void buscarClientePorDNI(int dni);
        void buscarClientePorNombre(const char* nombre);

    protected:

    private:
        char _Domicilio[50];
        char _Email[50];
        char _Telefono[15];
        int _Banco;
        /* BANCOS
        1 - Galicia
        2 - BBVA
        3 - ICBC
        4 - Santander
        5 - Macro
        */
        bool _Estado;
};

class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n){strcpy(nombre, n);};

        Cliente Leer_Registro(int pos);
        int Contar_Registro ();
        bool Grabar_Registro(Cliente reg);

};

#endif // CLIENTE_H_INCLUDED
