#include<iostream>
#include <cstdio>
#include "DetalleVenta.h"
#include "Vendedor.h"
using namespace std;


Vendedor::Vendedor() {
    //ctor
    setLegajo(0);
    setSalarioBase(0);
    setComision(0);
    setEstado(0);
}

void Vendedor::Cargar() {
    int leg;
    Fecha ing;
    float sal;

    cout << "Cargar vendedor: "<< endl;
    Persona::Cargar();
    cout << "Legajo: ";
    cin >> leg;
    cout << "Fecha de ingreso: ";
    ing.Cargar();
    cout << "Salario base: ";
    cin >> sal;

    setLegajo(leg);
    setIngreso(ing);
    setSalarioBase(sal);
    setEstado(1);
}

void Vendedor::Mostrar() {
    Fecha ing=getIngreso();

    cout << "Mostrar vendedor: " << endl;
    Persona::Mostrar();
    cout << "Legajo: " << getLegajo() << endl;
    cout << "Fecha de ingreso: ";
    ing.MostrarNumero();
    cout << endl;
    cout << "Salario Base: " << getSalarioBase() << endl;
    cout << "Comisiones acumuladas: " << getComision() << endl;
    cout << "Salario total: " << getSalarioTotal();

}

/*void Vendedor::calcularComision() {
    float monto, comi;

    monto=DetalleVenta::getMonto();

    comi=getComision() + (monto * 0.1); // 10% comision como ejemplo

    setComision(comi);
}*/

void Vendedor::salarioTotal() {
    float sal;

    sal= getSalarioBase() + getComision();

    setSalarioTotal(sal);

    // agregar webadas como obra social y aportes?
}

void Vendedor::Grabar_Archivo() {
    FILE *file = fopen("vendedores.dat", "ab");

    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }

    fwrite(this, sizeof(Vendedor), 1, file);
    fclose(file);
}

void Vendedor::Leer_Archivo() {
    FILE *file = fopen("vendedores.dat", "rb");

    if (file==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (fread(this, sizeof(Vendedor), 1, file)) {
        Mostrar();
    }
    fclose(file);
}
