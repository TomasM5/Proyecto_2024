#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#include<cstring>
#include "Fecha.h"

class Venta{
public:
    Venta();

    void Cargar();
    void Mostrar();

    void setID(int val) { _ID = val; }
    void setFecha(Fecha val) { _Fecha = val; }
    void setIDvendedor(int val) { _IDvendedor = val; }
    void setIDcliente(int val) { _IDcliente = val; }
    void setFormaPago(int val) { _FormaPago = val; }
    void setEnvio(bool val) { _Envio = val; }

    int getID(){ return _ID; }
    Fecha getFecha(){ return _Fecha; }
    int getIDvendedor(){ return _IDvendedor; }
    int getIDcliente(){ return _IDcliente; }
    int getFormaPago(){ return _FormaPago; }
    bool getEnvio(){ return _Envio; }

    void registrarVenta();
    void listarVentas();
    void buscarVenta();
    void historialVentas();
    void ventasPorCliente();
    void ventasPorProducto();
    bool Grabar_En_Disco();

private:
    int _ID;
    Fecha _Fecha;
    int _IDvendedor;
    int _IDcliente;
    int _FormaPago;
    bool _Envio;
};


class ArchivoVentas{
    private:
        char nombre[30];
    public:
        ArchivoVentas(const char *n){strcpy(nombre, n);};

        Venta Leer_Registro(int pos);
        int Contar_Registro ();
        bool Grabar_Registro(Venta reg);
        bool existeID(int id);
        bool borrarContenidoArchivo();

};

#endif // VENTA_H_INCLUDED
