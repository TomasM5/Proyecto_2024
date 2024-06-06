#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Persona.h"
#include "Fecha.h"


class Vendedor : public Persona {
    public:
        Vendedor();
        void Cargar();
        void Mostrar();
        void calcularComision();
        void salarioTotal();
        void Grabar_Archivo();
        void Leer_Archivo();

        void setLegajo(int val) { _Legajo = val; }
        void setSalarioBase(float val) { _SalarioBase = val; }
        void setSalarioTotal(float val) { _SalarioTotal = val; }
        void setComision(float val) { _Comision = val; }
        void setIngreso(Fecha val) { _Ingreso = val; }
        void setEstado(int val) { _Estado = val; }
        int getLegajo() { return _Legajo; }
        float getSalarioBase() { return _SalarioBase; }
        float getSalarioTotal() { return _SalarioTotal; }
        float getComision() { return _Comision; }
        Fecha getIngreso() { return _Ingreso; }
        int getEstado() { return _Estado; }

        void registrarVendedor();
        void listarVendedores();
        void buscarVendedor();
        void calcularSalarios();
        void ventasPorVendedor();

    protected:

    private:
        int _Legajo;
        float _SalarioBase;
        float _SalarioTotal;
        float _Comision;
        Fecha _Ingreso;
        int _Estado;
};

#endif // VENDEDOR_H
