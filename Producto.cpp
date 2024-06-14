#include<iostream>
#include<cstdio>
#include "Producto.h"
#include "Fecha.h"
using namespace std;


Producto::Producto() {
    _ID = 0;
    strcpy(_Marca, "");
    strcpy(_Descripcion, "");
    _Categoria = 0;
    _Stock = 0;
    _Valor = 0.0;
    _Estado = true;
    _Ingreso(0,0,0);
}

void Producto::Cargar(){
    cout << "Cargar Producto" << endl;
    cout << "ID: ";
    cin >> _ID;
    cin.ignore();
    cout << "Marca: ";
    cin.getline(_Marca, 20);
    cout << "Descripcion: ";
    cin.getline(_Descripcion, 50);
    cout << "Categoria: ";
    cin >> _Categoria;
    cout << "Stock: ";
    cin >> _Stock;
    cout << "Valor: ";
    cin >> _Valor;
    cout << "Estado (1 para activo, 0 para inactivo): ";
    cin >> _Estado;
    _Ingreso.Hoy();
}

void Producto::Mostrar(){
    cout << "Mostrar Producto" << endl;
    cout << "ID: " << _ID << endl;
    cout << "Marca: " << _Marca << endl;
    cout << "Descripcion: " << _Descripcion << endl;
    cout << "Categoria: " << _Categoria << endl;
    cout << "Stock: " << _Stock << endl;
    cout << "Valor: " << _Valor << endl;
    cout << "Estado: " << (_Estado ? "Activo" : "Inactivo") << endl;
}

int ArchivoProductos::Contar_Registro() {
    FILE *file=fopen(nombre, "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(Producto);
}

Producto ArchivoProductos::Leer_Registro(int pos){
    Producto reg;
    FILE *file;
    file=fopen(nombre, "rb");
    if(file==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return reg;
    }
    fseek(file, sizeof reg*pos,0);
    fread(&reg, sizeof reg,1, file);
    fclose(file);
    return reg;
}

bool ArchivoProductos::Grabar_Registro(Producto reg){
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return false;
    }
    int grabado=fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}


void Producto::buscarProductoPorID(){
    int idProducto;
    cout << "Ingrese el ID del producto: ";
    cin >> idProducto;

    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, file)){
        if(producto.getID() == idProducto){
            producto.Mostrar();
            cout << endl;
            fclose(file);
            return;
        }
    }
    cout << "Producto no encontrado" << endl;
    fclose(file);
}

void Producto::buscarProductoPorCategoria(){
    int categoria;
    cout << "Ingrese la categoria del prodcuto: ";
    cin >> categoria;

    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, file)){
        if(producto.getCategoria() == categoria){
            producto.Mostrar();
            cout << endl;
        }
    }
    fclose(file);
}

void Producto::buscarProductoPorRangoPrecio(){
    float precioMin, precioMax;
    cout << "Ingrese el rango de precio (min y max): ";
    cin >> precioMin >> precioMax;

    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, file)){
        if(producto.getValor() >= precioMin && producto.getValor() <= precioMax){
            producto.Mostrar();
            cout << endl;
        }
    }
    fclose(file);
}

void Producto::buscarProductoPorFechaIngreso(){
    Fecha fecha;
    cout << "Ingrese la fecha de ingreso (dd/mm/yyyy): ";
    fecha.Cargar();

    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, file)){
        if(producto.getFechaIngreso() == fecha){ ///TODO getFechaIngreso
            producto.Mostrar();
            cout << endl;
        }
    }
    fclose(file);
}

