#include<iostream>
#include<cstdio>
#include "Producto.h"
#include "Fecha.h"
using namespace std;


Producto::Producto() {
    Fecha a(0, 0, 0);
    _ID = 0;
    strcpy(_Marca, "");
    strcpy(_Descripcion, "");
    _Categoria = 0;
    _Stock = 0;
    _Valor = 0.0;
    _Estado = false;
    setFechaIngreso(a);
}

void Producto::Cargar(){
    cout << "Cargar Producto" << endl;
    ArchivoProductos archiP("productos.dat");
    int id;

    do {
        cout << "ID: ";
        cin >> id;
        if (archiP.existeID(id)) {
            cout << "El ID ya existe. Ingrese otro ID." << endl;
        } else {
            _ID = id;
            break;
        }
    } while (true);

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
    setEstado(1);
    _Ingreso.Hoy();
    cout << "Fecha del registro: ";
    _Ingreso.MostrarNumero();
    cout << endl;
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
    cout << "Fecha de ingreso: ";
    _Ingreso.MostrarNumero();
    cout << endl;
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

void Producto::registrarProducto(){///carga un nuevo producto y lo graba en el archivo
    ArchivoProductos file("productos.dat");
    Cargar();
    file.Grabar_Registro(*this);
    cout << "Producto registrado exitosamente" << endl;
}

void Producto::listarProductos(){ ///muestra todos los productos registrados
    Producto aux;
    ArchivoProductos file("productos.dat");
    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i++){
        aux = file.Leer_Registro(i);
        if(aux.getEstado()){
            aux.Mostrar();
            cout << endl;
        }
    }
    system("pause");
}

void Producto::buscarProductoPorID(){
    ArchivoProductos file("productos.dat");
    Producto prod;

    bool encontrado = false;
    int id;
    cout << "Ingrese ID del producto: ";
    cin >> id;

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        prod = file.Leer_Registro(i);
        if(prod.getID() == id && prod.getEstado()){
            encontrado = true;
            prod.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "Producto no encontrado" << endl;
    }
}

void Producto::buscarProductoPorCategoria(){
    ArchivoProductos file("productos.dat");
    Producto prod;
    int categoria;
    cout << "Categorias existentes:" << endl;
    cout << "1 - Muebles" << endl;
    cout << "2 - Iluminacion" << endl;
    cout << "3 - Cuadros" << endl;
    cout << "4 - Textiles" << endl;
    cout << "5 - Plantas artificiales" << endl;
    cout << "6 - Ceramicas" << endl;
    cout << endl;
    cout << "Ingrese la categoria del producto a buscar: ";
    cin >> categoria;

    bool encontrado = false;

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        prod = file.Leer_Registro(i);
        if(prod.getCategoria() == categoria && prod.getEstado()){
            encontrado = true;
            prod.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "Producto no encontrado" << endl;
    }
}

void Producto::buscarProductoPorRangoPrecio(){
    ArchivoProductos file("productos.dat");
    Producto prod;
    float precioMin, precioMax;
    cout << "Ingrese el rango de precio (min y max): " << endl;
    cout << "min: ";
    cin >> precioMin;
    cout << "max: ";
    cin >> precioMax;

    int cantReg = file.Contar_Registro();

    for(int i = 0; i < cantReg; i ++){
        prod = file.Leer_Registro(i);
        if(prod.getValor() >= precioMin && prod.getValor() <= precioMax){
            prod.Mostrar();
            cout << endl;
        }
    }
}

void Producto::buscarProductoPorFechaIngreso(){
    Fecha fecha;
    cout << "Ingrese la fecha de ingreso (dd/mm/yyyy): " << endl;
    fecha.Cargar();
    cout << endl;

    FILE *file = fopen("productos.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    bool encontrado = false;
    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, file)){
        if(producto.getFechaIngreso() == fecha){
            encontrado = true;
            producto.Mostrar();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "No se encontro producto en la fecha ingresada" << endl;
    }

    fclose(file);
}


void Producto::ordenarPrecio(Producto *registros,int cantidad, char *orden) {
    int posMax, posMin;
    Producto aux;

    for (int i=0; i<cantidad-1; i++) {

        posMax=posMin=i;

        for (int j=i+1; j<cantidad; j++){

            if (registros[j].getValor()>registros[posMax].getValor()) posMax=j;
            if (registros[j].getValor()<registros[posMin].getValor()) posMin=j;
        }

        if (strcmp(orden, "mayor")==0 && posMax!=i) {
            aux=registros[i];
            registros[i]=registros[posMax];
            registros[posMax]=aux;
        }
        if (strcmp(orden, "menor")==0 && posMin!=i) {
            aux=registros[i];
            registros[i]=registros[posMin];
            registros[posMin]=aux;
        }
    }
}

void Producto::ordenarDescripcion(Producto *registros,int cantidad){
    int posMin;
    Producto aux;

    for (int i=0; i<cantidad-1; i++) {

        posMin=i;

        for (int j=i+1; j<cantidad; j++){

            if (strcmp(registros[j].getDescripcion(),registros[posMin].getDescripcion())==-1) posMin=j;
        }

        if (posMin!=i) {
            aux=registros[i];
            registros[i]=registros[posMin];
            registros[posMin]=aux;
        }
    }
}

void Producto::ordenarCategoria(Producto *registros,int cantidad){
    int posAux, posMin, categoria=1;
    Producto aux;

    for (int i=1; i<6; i++){

    }

    for (int i=0; i<cantidad; i++) {
        posMin=i;
        for (int j=i+1; j<cantidad; j++){
            if (strcmp(registros[j].getDescripcion(), registros[posMin].getDescripcion())==-1) posMin=j;
        }

        if (posMin!=i) {
            aux=registros[i];
            registros[i]=registros[posMin];
            registros[posMin]=aux;
        }
    }
}

void Producto::registrarProductosEnLote(){
    Producto *lote;
    int cantidad;

    cout << "Cuantos productos diferentes desea agregar? ";
    cin >> cantidad;

    lote=new Producto[cantidad];

    for (int i = 0; i < cantidad; i++){
        cout << endl;
        cout << "Producto " << i+1 << ":" << endl;
        lote[i].registrarProducto();
    }
    system("pause");
    delete []lote;
}


bool ArchivoProductos::existeID(int id) {
    int cantReg = Contar_Registro();
    for (int i = 0; i < cantReg; i++) {
        Producto producto = Leer_Registro(i);
        if (producto.getID() == id) {
            return true;
        }
    }
    return false;
}

bool ArchivoProductos::borrarContenidoArchivo(){
    FILE *file = fopen("productos.dat", "wb");
    if (file == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    fclose(file);
    cout << "Contenido del archivo borrado exitosamente." << endl;
    return true;
}

//void Producto::ordenarIngreso();
