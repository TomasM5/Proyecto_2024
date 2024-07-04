#include<iostream>
#include<cstdio>
#include "Venta.h"
#include "DetalleVenta.h"
#include "Producto.h"
using namespace std;

Venta::Venta() {
    _ID = 0;
    _IDvendedor = 0;
    _IDcliente = 0;
    _FormaPago = 0;
    _Envio = false;
}

void Venta::Cargar() {
    ArchivoVentas archiV("ventas.dat");

    cout << "Cargar Venta" << endl;
    int id;
    do {
        cout << "ID: ";
        cin >> id;
        if (archiV.existeID(id)) {
            cout << "El ID ya existe. Ingrese otro ID." << endl;
        } else {
            _ID = id;
            break;
        }
    } while (true);

    _Fecha.Cargar();
    cout << "ID Vendedor: ";
    cin >> _IDvendedor;
    cout << "ID Cliente: ";
    cin >> _IDcliente;
    cout << "Forma de Pago: ";
    cin >> _FormaPago;
    cout << "Envio (1 si, 0 no): ";
    cin >> _Envio;
}

void Venta::Mostrar() {
    cout << "Mostrar Venta" << endl;
    cout << "ID: " << _ID << endl;
    _Fecha.MostrarNumero();
    cout << endl;
    cout << "ID Vendedor: " << _IDvendedor << endl;
    cout << "ID Cliente: " << _IDcliente << endl;
    cout << "Forma de Pago: " << _FormaPago << endl;
    cout << "Envio: " << (_Envio ? "Si" : "No") << endl;
}

int ArchivoVentas::Contar_Registro() {
    FILE *file=fopen(nombre, "rb");
    if (file==NULL) {return -1;}
    fseek(file, 0, 2);
    int tam=ftell(file);
    fclose(file);
    return tam/sizeof(Venta);
}

Venta ArchivoVentas::Leer_Registro(int pos){
    Venta reg;
    FILE *p = fopen(nombre, "rb");
    if(p==NULL) {
        cout << "Error al abrir el archivo." << endl;
        return reg;
    }
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fread(&reg, sizeof(Venta), 1, p);
    fclose(p);
    return reg;
}

bool ArchivoVentas::Grabar_Registro(Venta reg){
    FILE *file = fopen(nombre, "ab");
    if(file == NULL){
      cout << "Error al abrir el archivo." << endl;
      return false;
    }
    int grabado=fwrite(&reg, sizeof(reg), 1, file);
    fclose(file);
    return grabado;
}

void Venta::registrarVenta(){///registra la venta y la carga en el archivo
    Venta aux;
    ArchivoVentas filevent("ventas.dat");
    DetalleVenta detail;
    ArchivoDetalle filedet("detalle_ventas.dat");
    Producto prod;
    int idprod;
    ArchivoProductos fprod("productos.dat");

    detail.Cargar();
    aux=detail.getVenta();
    idprod=detail.getIDproducto();

    filevent.Grabar_Registro(aux);
    filedet.Grabar_Registro(detail);

    //  LA SIGUIENTE SECCION MODIFICA EL STOCK EN INVENTARIO DEL PRODUCTO VENDIDO
    /*int i=0, tam;
    bool fin=false;
    while (!fin){
        prod=fprod.Leer_Registro(i);
        if (prod.getID()==idprod){

            int stock=prod.getStock() - detail.getCantidad();
            prod.setStock(stock);
            if (prod.getStock()==0) prod.setEstado(0);

            tam=sizeof(Producto) * i;
            FILE *p;
            p=fopen("productos.dat", "rb+");
            if(p == NULL) cout << "Error al abrir el archivo" << endl; return;

            fseek(p,tam,0); // desplaza el cursor hasta la posicion del producto actual

            fwrite(&prod, sizeof(prod), 1, p);

            fclose(p);

        }
        if (prod.getID()==0) {
            fin=true;
        }
        i++;
    }*/
    cout << endl;
    cout << "Venta registrada exitosamente" << endl;
}

void Venta::listarVentas(){///lista todas las ventas del archivo
    ArchivoVentas file ="ventas.dat";
    Venta venta;
    int i=0;
    bool fin=false;
    do{
        venta=file.Leer_Registro(i);
        if (venta.getID()==0){
            fin=true;
            break;
        }
        venta.Mostrar();
        cout << endl;
        i++;
    }while (!fin);
}

void Venta::buscarVenta(){///busca una venta por su ID
    int id;
    cout << "Ingrese el ID de la venta: ";
    cin >> id;

    Venta venta;
    ArchivoVentas file="ventas.dat";
    DetalleVenta aux;
    ArchivoDetalle fdeta="detalle_ventas.dat";
    bool encontrado = false;
    bool fin=false;
    int i=0;
    do{
        venta=file.Leer_Registro(i);
        aux=fdeta.Leer_Registro(i);
        if (venta.getID()==0){
            fin=true;
            break;
        }
        if(venta.getID() == id){
            char opcion;
            cout << "Desea ver el detalle? (s/n): ";
            cin >> opcion;
            if (opcion=='s' || opcion=='S') aux.Mostrar();
            else venta.Mostrar();
            encontrado = true;
            fin=true;
            break;
        }
        i++;
    }while(!fin);
    if(!encontrado){
        cout << "Venta no encontrada" << endl;
        return;
    }
}

void Venta::historialVentas(){///muestra el historial de ventas de una fecha especifica o de todo
    ArchivoVentas file("ventas.dat");
    Venta venta;
    ArchivoDetalle fdet("detalle_ventas.dat");
    DetalleVenta detalle;
    Fecha fecha;

    char opcion;
    bool fechaEncontrada = false;

    cout << "Desea consultar por fecha especifica? (s/n): ";
    cin >> opcion;

    if(opcion == 's' || opcion == 'S') {
        cout << "Ingrese la fecha (dd/mm/yyyy): " << endl;
        fecha.Cargar();
        cout << endl;

        int cantReg = file.Contar_Registro();
        for(int i = 0; i < cantReg; i++) {
            venta = file.Leer_Registro(i);
            if(venta.getFecha() == fecha) {
                fechaEncontrada = true;
                break;
            }
        }

        if(fechaEncontrada) {
            cout << "Desea ver el detalle? (s/n): ";
            cin >> opcion;
            cout << endl;

            if(opcion == 's' || opcion == 'S') {
                int cantRegDet = fdet.Contar_Registro();
                for(int i = 0; i < cantRegDet; i++) {
                    detalle = fdet.Leer_Registro(i);
                    if(detalle.getVenta().getID() == venta.getID()) {
                        detalle.Mostrar();
                        cout << endl;
                    }
                }
            } else {
                venta.Mostrar();
            }
        } else {
            cout << "No se encontraron ventas en esa fecha." << endl;
        }
    } else {
        cout << "Desea ver el detalle de todas las ventas? (s/n): ";
        cin >> opcion;
        cout << endl;

        if(opcion == 's' || opcion == 'S') {
            int cantRegDet = fdet.Contar_Registro();
            for(int i = 0; i < cantRegDet; i++) {
                detalle = fdet.Leer_Registro(i);
                detalle.Mostrar();
                cout << endl;
            }
        } else {
            int cantRegVen = file.Contar_Registro();
            for(int i = 0; i < cantRegVen; i++) {
                venta = file.Leer_Registro(i);
                venta.Mostrar();
                cout << endl;
            }
        }
    }
}


void Venta::ventasPorCliente(){///muestra todas las ventas por cliente
    int idCliente;
    char opc;
    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    cout << "Desea ver el detalle? (s/n)";
    cin >> opc;

    ArchivoVentas file = "ventas.dat";
    Venta venta;
    ArchivoDetalle fdet= "detalle_ventas.dat";
    DetalleVenta detail;
    bool fin=false;
    bool encontrado=false;
    int i=0;
    while(!fin){
        venta=file.Leer_Registro(i);
        detail= fdet.Leer_Registro(i);

        if (venta.getID()==0){
            fin=true;
            break;
        }
        if(venta.getIDcliente() == idCliente){
            if(opc=='s' || opc=='S') detail.Mostrar();
            else venta.Mostrar();
            encontrado=true;
            cout << endl;
            break;
        }
        i++;
    }

    if (!encontrado){
        cout << "No se registran ventas para el cliente indicado." << endl;
    }
}


void Venta::ventasPorProducto(){///muestra las ventas por producto
    int idProducto;
    cout << "Ingrese el ID del producto: ";
    cin >> idProducto;

    ArchivoDetalle fdet="detalle_ventas.dat";
    DetalleVenta detalleventa;
    bool encontrado = false;
    bool fin = false;
    int i=0;

    while(!fin){
        detalleventa=fdet.Leer_Registro(i);

        if(detalleventa.getIDVenta()==0){
            fin=true;
            break;
        }
        if(detalleventa.getIDproducto() == idProducto){
            detalleventa.Mostrar();
            encontrado = true;
        }
        i++;
    }
    if(!encontrado){
        cout << "No se encontraron ventas para ese producto" << endl;
    }
}

bool Venta::Grabar_En_Disco() {
    FILE *p = fopen("ventas.dat", "ab");
    if (p == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    bool ok = fwrite(this, sizeof(Venta), 1, p);
    fclose(p);
    return ok;
}

bool ArchivoVentas::existeID(int id) {
    int totalRegistros = Contar_Registro();
    for (int i = 0; i < totalRegistros; i++) {
        Venta venta = Leer_Registro(i);
        if (venta.getID() == id) {
            return true;
        }
    }
    return false;
}

bool ArchivoVentas::borrarContenidoArchivo() {
    FILE *file = fopen(nombre, "wb");
    if (file == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    fclose(file);
    cout << "Contenido del archivo borrado exitosamente." << endl;
    return true;
}


