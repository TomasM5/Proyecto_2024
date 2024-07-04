#include<iostream>
#include <cstdio>
#include "DetalleVenta.h"
#include "Vendedor.h"
using namespace std;


Vendedor::Vendedor(){
    setLegajo(0);
    setSalarioBase(0);
    setComision(0);
    setEstado(0);
}

void Vendedor::Cargar(){
    int leg;
    Fecha ing;
    float sal;

    cout << "Cargar vendedor: "<< endl;
    Persona::Cargar();
    cout << "Legajo: ";
    cin >> leg;
    cout << "Fecha de ingreso: " << endl;
    ing.Cargar();
    cout << "Salario base: ";
    cin >> sal;

    setLegajo(leg);
    setIngreso(ing);
    setSalarioBase(sal);
    setComision(0);
    setEstado(1);
}

void Vendedor::Mostrar(){
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
    cout << endl;

}

int ArchivoVendedores::Contar_Registro() {
    FILE *p = fopen (nombre, "rb");
    if (p==NULL) {return -1;}
    fseek (p, 0, 2);
    int tam=ftell(p);
    return tam/sizeof (Vendedor);
}

bool ArchivoVendedores::Grabar_Registro(Vendedor reg){
    FILE *file = fopen(nombre, "ab");

    if(file == NULL){
      cout << "Error al abrir el archivo" << endl;
      return false;
    }

    int grabado=fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}

Vendedor ArchivoVendedores::Leer_Registro(int pos){
    Vendedor reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) {
            cout << "Error al abrir el archivo." << endl;
            return reg;
        }
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
}

void ArchivoVendedores::Copia_Seguridad(){
    Vendedor reg;
    FILE *copia=fopen("copia_seguridad_vendedores.dat", "wb");

    int cantidad=Contar_Registro();

    for (int i=0; i<cantidad; i++) {
        reg=Leer_Registro(i);
        fwrite(&reg, sizeof(reg), 1, copia);
    }
    fclose (copia);
    cout << "Copia de seguridad realizada exitosamente." << endl;

}

void ArchivoVendedores::Restaurar(){
    Vendedor reg;
    ArchivoVendedores copia("copia_seguridad_vendedores.dat");
    int cant=copia.Contar_Registro();

    for(int i=0; i<cant; i++){
        reg=copia.Leer_Registro(i);
        Grabar_Registro(reg);
    }

    cout << "Copia de seguridad restaurada exitosamente." << endl;
}

void Vendedor::registrarVendedor(){ ///carga un nuevo vendedor y lo guarda en el archivo
    ArchivoVendedores file("vendedores.dat");
    Cargar();
    file.Grabar_Registro(*this);
    cout << "Vendedor registrado correctamente" << endl;
}

void Vendedor::listarVendedores(){ ///muestra todos los vendedores registrado
    Vendedor vendedor;
    ArchivoVendedores file("vendedores.dat");
    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        vendedor = file.Leer_Registro(i);
        if(vendedor.getEstado()){
            vendedor.Mostrar();
            cout << endl;
        }
    }
}

void Vendedor::buscarVendedor(){ ///busca y muestra un vendedor por su legajo
    int legajo;
    cout << "Ingrese el legajo del vendedor: ";
    cin >> legajo;

    FILE* file=fopen("vendedores.dat", "rb");
    if (file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Vendedor vendedor;
    bool encontrado = false;

    while(fread(&vendedor, sizeof(Vendedor), 1, file)){
        if(vendedor.getLegajo() == legajo){
            vendedor.Mostrar();
            encontrado = true;
            break;
        }
    }
    fclose(file);

    if(!encontrado){
        cout << "No se encontro un vendedor con el legajo " << legajo << endl;
    }
}

void Vendedor::ventasPorVendedor(){///lista todas las ventas realizadas por un vendedor especifico
    int legajo;
    cout << "Ingrese el legajo del vendedor: ";
    cin >> legajo;

    Vendedor vendedor;
    FILE *archemp= fopen("vendedores.dat", "rb");
    if (archemp==NULL){
        cout << "Error al abrir el archivo de vendedores"<< endl;
        return;
    }
    while (fread(&vendedor, sizeof(Vendedor), 1, archemp)){
        if (vendedor.getLegajo()==legajo){
            cout << "Vendedor encontrado: " << endl;
            vendedor.Mostrar();
            break;
        }
    }
    fclose(archemp);

    cout << endl;

    FILE *file = fopen("ventas.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo de ventas" << endl;
        return;
    }

    Venta venta;
    bool encontrado = false;
    while(fread(&venta, sizeof(Venta), 1, file)){
        if(venta.getIDvendedor() == vendedor.getID()){
            venta.Mostrar();
            cout << endl;
            encontrado = true;
        }
    }
    fclose(file);

    if (!encontrado) {
        cout << "No se encontraron ventas para el legajo " << legajo << endl;
    }
}

bool ArchivoVendedores::borrarContenidoArchivo(){
    FILE *file = fopen("vendedores.dat", "wb");
    if (file == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    fclose(file);
    cout << "Contenido del archivo borrado exitosamente." << endl;
    return true;
}
