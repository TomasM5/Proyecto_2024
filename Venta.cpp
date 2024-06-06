#include<iostream>
#include<cstdio>
#include "Venta.h"
#include "DetalleVenta.h"
using namespace std;

Venta::Venta() {
    _ID = 0;
    _IDvendedor = 0;
    _IDcliente = 0;
    _FormaPago = 0;
    _Envio = false;
}

void Venta::Cargar() {
    cout << "Cargar Venta" << endl;
    cout << "ID: ";
    cin >> _ID;
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
    cout << "ID Vendedor: " << _IDvendedor << endl;
    cout << "ID Cliente: " << _IDcliente << endl;
    cout << "Forma de Pago: " << _FormaPago << endl;
    cout << "Envio: " << (_Envio ? "Si" : "No") << endl;
}

void Venta::registrarVenta(){///registra la venta y la carga en el archivo
    Cargar();
    FILE *file = fopen("ventas.dat", "ab");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fwrite(this, sizeof(Venta), 1, file);
    fclose(file);
    cout << "Venta registrada exitosamente" << endl;
}

void Venta::listarVentas(){///lista todas las ventas del archivo
    FILE *file = fopen("ventas.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Venta venta;
    while(fread(&venta, sizeof(Venta), 1, file)){
        venta.Mostrar();
        cout << endl;
    }
    fclose(file);
}

void Venta::buscarVenta(){///busca una venta por su ID
    int id;
    cout << "Ingrese el ID de la venta: ";
    cin >> id;

    FILE *file = fopen("ventas.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Venta venta;
    bool encontrado = false;
    while(fread(&venta, sizeof(Venta), 1, file)){
        if(venta.getID() == id){
            venta.Mostrar();
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "Venta no encontrada" << endl;
    }
    fclose(file);
}

void Venta::historialVentas(){///muestra el historial de ventas de una fecha especifica o de todo
    FILE *file = fopen("ventas.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Venta venta;
    Fecha fecha;
    char opcion;
    cout << "Desea consultar por fecha especifica? (s/n): ";
    cin >> opcion;

    if(opcion == 's' || opcion == 'S'){
        cout << "Ingrese la fecha (dd/mm/yyyy): ";
        fecha.Cargar();
        while(fread(&venta, sizeof(Venta), 1, file)){
            if(venta.getFecha() == fecha){
                venta.Mostrar();
                cout << endl;
            }
        }
    }
    else{
        while(fread(&venta, sizeof(Venta), 1, file)){
            venta.Mostrar();
            cout << endl;
        }
    }

    fclose(file);
}

void Venta::ventasPorCliente(){///muestra todas las ventas por cliente
    int idCliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

    FILE *file = fopen("ventas.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    Venta venta;
    while(fread(&venta, sizeof(Venta), 1, file)){
        if(venta.getIDcliente() == idCliente){
            venta.Mostrar();
            cout << endl;
            break;
        }
    }
    fclose(file);
}

/**
REVISAR ESTA FUNCION

void Venta::ventasPorProducto(){///muestra las ventas por producto
    int idProducto;
    cout << "Ingrese el ID del producto: ";
    cin >> idProducto;

    FILE *file = fopen("detalles_venta.dat", "rb");
    if(file == NULL){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    DetalleVenta detalleventa;
    bool encontrado = false;

    while(fread(&detalleventa, sizeof(DetalleVenta), 1, file)){
        if(detalleventa.getIDproducto == idProducto){
            detalleventa.Mostrar();
            encontrado = true;
        }
    }
    if(!encontrado){
        cout << "No se encontraron ventas para ese producto" << endl;
    }
    fclose(file);
}**/

