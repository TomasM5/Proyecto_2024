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
    aux.Cargar();
    ArchivoVentas file = "ventas.dat";

    file.Grabar_Registro(aux);
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
    bool encontrado = false;
    bool fin=false;
    int i=0;
    do{
        venta=file.Leer_Registro(i);
        if (venta.getID()==0){
            fin=true;
            break;
        }
        if(venta.getID() == id){
            venta.Mostrar();
            encontrado = true;
            break;
        }
        i++;
    }while(!fin);
    if(!encontrado){
        cout << "Venta no encontrada" << endl;
    }
}

void Venta::historialVentas(){///muestra el historial de ventas de una fecha especifica o de todo
    ArchivoVentas file = "ventas.dat";
    Venta venta;
    Fecha fecha;
    char opcion;
    int i=0;
    bool fin=false;
    cout << "Desea consultar por fecha especifica? (s/n): ";
    cin >> opcion;

    if(opcion == 's' || opcion == 'S'){
        cout << "Ingrese la fecha (dd/mm/yyyy): ";
        fecha.Cargar();
        do{
            venta=file.Leer_Registro(i);
            if(venta.getID()==0){
                fin=true;
                break;
            }
            if(venta.getFecha() == fecha){
                venta.Mostrar();
                cout << endl;
            }
            i++;
        }while(!fin);
    }
    else{
        while(!fin){
            venta=file.Leer_Registro(i);
            if(venta.getID()==0){
                fin=true;
                break;
            }
            venta.Mostrar();
            cout << endl;
            i++;

        }
    }
}

void Venta::ventasPorCliente(){///muestra todas las ventas por cliente
    int idCliente;
    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;

    ArchivoVentas file = "ventas.dat";
    Venta venta;
    bool fin=false;
    int i=0;
    while(!fin){
        venta=file.Leer_Registro(i);
        if (venta.getID()==0){
            fin=true;
            break;
        }
        if(venta.getIDcliente() == idCliente){
            venta.Mostrar();
            cout << endl;
            break;
        }
        i++;
    }
}


//REVISAR ESTA FUNCION

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
    int i=0;

    while(fread(&detalleventa, sizeof(DetalleVenta), 1, file)){
        if(detalleventa.getIDproducto() == idProducto){
            detalleventa.Mostrar();
            encontrado = true;
        }
        fseek(file,sizeof(DetalleVenta)*i,0); // hace que el cursor avance en el archivo -T
        i++;
    }
    if(!encontrado){
        cout << "No se encontraron ventas para ese producto" << endl;
    }
    fclose(file);
}


