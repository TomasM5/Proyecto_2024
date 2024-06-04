#include<iostream>
#include<cstdio>
#include "Producto.h"
using namespace std;


Producto::Producto() {
    _ID = 0;
    strcpy(_Marca, "");
    strcpy(_Descripcion, "");
    _Categoria = 0;
    _Stock = 0;
    _Valor = 0.0;
    _Estado = true;
}

void Producto::Cargar() {
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
}

void Producto::Mostrar() {
    cout << "Mostrar Producto" << endl;
    cout << "ID: " << _ID << endl;
    cout << "Marca: " << _Marca << endl;
    cout << "Descripcion: " << _Descripcion << endl;
    cout << "Categoria: " << _Categoria << endl;
    cout << "Stock: " << _Stock << endl;
    cout << "Valor: " << _Valor << endl;
    cout << "Estado: " << (_Estado ? "Activo" : "Inactivo") << endl;
}

void Producto::Grabar_Archivo() {
    FILE *file = fopen("productos.dat", "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    fwrite(this, sizeof(Producto), 1, file);
    fclose(file);
}

void Producto::Leer_Archivo() {
    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    while(fread(this, sizeof(Producto), 1, file)){
        Mostrar();
    }
    fclose(file);
}
