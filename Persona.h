#ifndef PERSONA_H
#define PERSONA_H
#include "stdio.h"
#include "string.h"
#include "Fecha.h"

class Persona
{
    public:
        Persona();

        void setID (int val) { _ID = val; }
        void setNombre (char *val) { strcpy(_Nombre, val); }
        void setApellido (char *val) { strcpy(_Apellido, val); }
        void setNacimiento(Fecha val) { _Nacimiento = val; }
        void setDNI(int val) { _DNI = val; }
        int getID () { return _ID; }
        const char *getNombre () { return _Nombre; }
        const char *getApellido () { return _Apellido; }
        Fecha getNacimiento() { return _Nacimiento; }
        int getDNI() { return _DNI; }

    protected:
        int _ID;
        char _Nombre[20];
        char _Apellido[20];
        Fecha _Nacimiento;
        int _DNI;

    private:
};

#endif // PERSONA_H
