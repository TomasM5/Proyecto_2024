#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>
#include <iostream>

using namespace std;

void Nombre_Local(){
    cout << "           --------    DECORACIONES LUZ TORMENTOSA   ------" << endl << endl;
}

void Menu_Principal(){
    system("cls");
    Nombre_Local();
    cout << "           --------    MENU PRINCIPAL  -----------" << endl << endl;
    cout << "1 - Ventas" << endl;
    // -> registrar ventas, historial de ventas, busqueda de venta (id, cliente)

    cout << "2 - Clientes" << endl;
    // -> nuevo cliente, listar clientes, buscar cliente (id, dni, nombre)

    cout << "3 - Inventario" << endl;
    // -> listar stock, buscar producto (por id, marca), restock, nuevo producto

    cout << "4 - Vendedores" << endl;
    //cargar vendedor,listar/buscar vendedor, salarios, ventas por vendedor

    cout << "5 - Proveedores" << endl;
    // reportes de compras del local?

    cout << "6 - Recaudaciones" << endl;

    cout << "7 - Configuracion" << endl;
    // ->  cargar proveedor,copias de seguridad

    cout << "0 - Salir";

    cout << endl << endl;
    cout << "Ingrese la opcion: ";

}

void Menu_Ventas(){
    system("cls");
    Nombre_Local();
    cout << "           -------     VENTAS   ----------" << endl << endl;
    cout << "1 - Registrar Venta" << endl;
    cout << "2 - Historial de ventas" << endl; // listado de venta por fecha, ¿incluir consulta aca? puede solicitar fecha y de lo contrario mostrar todo
    cout << "3 - Buscar venta por ID" << endl;
    cout << "4 - Ventas por cliente" << endl;
    cout << "5 - Ventas por producto" << endl;
    cout << "6 - Borrar archivo de ventas" << endl;
    cout << "7 - Borrar archivo de detalle ventas" << endl;
    cout << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
    //  producto mas vendido?
}

void SubMenuVentas(){
    int opcVentas;
    Venta venta;
    ArchivoVentas archiV("ventas.dat");
    ArchivoDetalle archiD("detalle_ventas.dat");

    do{
        Menu_Ventas();
        cin >> opcVentas;
        switch(opcVentas) {
            case 1:
                venta.registrarVenta();
                break;
            case 2:
                venta.historialVentas();
                break;
            case 3:
                venta.buscarVenta();
                break;
            case 4:
                venta.ventasPorCliente();
                break;
            case 5:
                venta.ventasPorProducto();
                break;
            case 6:
                archiV.borrarContenidoArchivo();
                break;
            case 7:
                archiD.borrarContenidoArchivo();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
            }
        if(opcVentas != 0) system("pause");
    }while(opcVentas != 0);
}

void Menu_Clientes(){
    system("cls");
    Nombre_Local();
    cout << "           -------     CLIENTES   ----------" << endl << endl;
    cout << "1 - Registrar cliente nuevo" << endl;
    cout << "2 - Lista de clientes" << endl;
    cout << "3 - Buscar cliente" << endl;
    cout << "4 - Buscar DNI" << endl;
    cout << "5 - Buscar nombre" << endl;
    cout << "6 - Borrar archivo cliente" << endl;
    cout << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
    //consulta por tipo de consumidor?
}

void SubMenuClientes(){
    int opcClientes;
    Cliente cliente;
    ArchivoClientes archiC("clientes.dat");
    do {
        Menu_Clientes();
        cin >> opcClientes;
        switch (opcClientes) {
            case 1:
                cliente.registrarCliente();
                break;
            case 2:
                cliente.listarClientes();
                break;
            case 3:
                cliente.buscarClientePorID();
                break;
            case 4:
                cliente.buscarClientePorDNI();
                break;
            case 5:
                cliente.buscarClientePorNombre();
                break;
            case 6:
                archiC.borrarContenidoArchivo();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                return;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
        if(opcClientes != 0) system("pause");
    } while (opcClientes != 0);
}

void Lista_Clientes(){
    system("cls");
    Nombre_Local();
    cout << "LISTAR CLIENTES" << endl;
    cout << "Elija el orden" << endl;
    cout << "1 - Por apellido" << endl;
    cout << "2 - Por numero de registro" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void Menu_Inventario(){
    system("cls");
    Nombre_Local();
    cout << "           --------    INVENTARIO  -----------" << endl << endl;
    cout << "1 - Mostrar inventario" << endl;
    cout << "2 - Menu productos" << endl;
    cout << "3 - Anadir nuevo producto" << endl;
    cout << "4 - Anadir lote de productos" << endl;
    cout << "5 - Compra de stock" << endl;
    cout << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void Menu_Productos(){
    system("cls");
    Nombre_Local();
    cout << "           --------    PRODUCTOS  -----------" << endl << endl;
    cout << "1 - Buscar por ID" << endl;
    cout << "2 - Buscar por categoria" << endl;
    cout << "3 - Buscar por rango de precio" << endl;
    cout << "4 - Buscar por fecha de ingreso" << endl;
    cout << "5 - Borrar archivo de productos" << endl;
    cout << endl;
    cout << "0 - Volver al menu de inventario" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void SubMenuProductos(){
    int opcProductos;
    Producto producto;
    ArchivoProductos archiP("productos.dat");
    do {
        Menu_Productos();
        cin >> opcProductos;
        switch (opcProductos) {
            case 1:
                producto.buscarProductoPorID();
                break;
            case 2:
                producto.buscarProductoPorCategoria();
                break;
            case 3:
                producto.buscarProductoPorRangoPrecio();
                break;
            case 4:
                producto.buscarProductoPorFechaIngreso();
                break;
            case 5:
                archiP.borrarContenidoArchivo();
                break;
            case 0:
                cout << "Volviendo al menu de inventario..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcProductos != 0) system("pause");
    } while (opcProductos != 0);
}

void SubMenuInventario(){
    int opcInv;
    Producto prod;
    Compra compra;
    do {
        Menu_Inventario();
        cin >> opcInv;
        switch (opcInv) {
            case 1:
                prod.listarProductos();
                break;
            case 2:
                SubMenuProductos();
                break;
            case 3:
                prod.registrarProducto();
                break;
            case 4:
                prod.registrarProductosEnLote();
                break;
            case 5:
                compra.Cargar();
                ///TODO -> guardar compra en archivo
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opción invalida. Intente nuevamente" << endl;
                break;
        if (opcInv != 0) system("pause");
        }
    }while (opcInv != 0);
}

void Lista_Inventario(){
    system("cls");
    Nombre_Local();
    cout << "LISTAR INVENTARIO" << endl;
    cout << "Elija el orden" << endl;
    cout << "1 - Por precio de venta" << endl;
    cout << "2 - Por descripcion" << endl;
    cout << "3 - Por categoria" << endl;
    cout << "4 - Por fecha de ingreso" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void Menu_Vendedores(){
    system("cls");
    Nombre_Local();
    cout << "           -------     VENDEDORES   ----------" << endl << endl;
    cout << "1 - Registrar Vendedor" << endl;
    cout << "2 - Listar Vendedores" << endl;
    cout << "3 - Buscar Vendedor" << endl;
    cout << "4 - Ventas por Vendedor" << endl;
    cout << "5 - Borrar archivo de vendedores" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void SubMenuVendedores(){
    int opcVendedores;
    Vendedor vendedor;
    ArchivoVendedores archiV("vendedores.dat");
    do {
        Menu_Vendedores();
        cin >> opcVendedores;
        switch (opcVendedores) {
            case 1:
                vendedor.registrarVendedor();
                break;
            case 2:
                vendedor.listarVendedores();
                break;
            case 3:
                vendedor.buscarVendedor();
                break;
            case 4:
                vendedor.ventasPorVendedor();
                break;
            case 5:
                archiV.borrarContenidoArchivo();
                break;
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcVendedores != 0) system("pause");
    } while (opcVendedores != 0);
}

void Menu_Proveedores(){
    system("cls");
    Nombre_Local();
    cout << "           -------     PROVEEDORES   ----------" << endl << endl;
    cout << "1 - Registrar Proveedor" << endl;
    cout << "2 - Listar Proveedores" << endl;
    cout << "3 - Buscar Proveedor" << endl;
    cout << "4 - Compras por Proveedor" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void SubmenuProveedores(){
    int opcProveedores;
    Proveedor proveedor;
    do{
        Menu_Proveedores();
        cin >> opcProveedores;
        switch (opcProveedores){
            case 1:
                proveedor.registrarProveedor();
                break;
            case 2:
                proveedor.listarProveedores();
                break;
            case 3:
                proveedor.buscarProveedor();
                break;
            case 4:
                proveedor.comprasPorProveedor();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcProveedores != 0) system("pause");
    }while(opcProveedores != 0);
}

void Menu_Recaudacion(){
    system("cls");
    Nombre_Local();
    cout << "           -------     RECAUDACION   ----------" << endl << endl;
    cout << "1 - Listar recaudacion anual" << endl;
    cout << "2 - Listar recaudacion mensual" << endl;
    cout << "3 - Listar recaudacion por cliente" << endl;
    cout << "4 - Listar recaudacion por producto" << endl;
    cout << "5 - Listar productos por categoria" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void SubmenuRecaudacion(){
    int opcRecaudacion;
    ArchivoDetalle archiD("detalleventas.h");
    do{
        Menu_Recaudacion();
        cin >> opcRecaudacion;
        switch (opcRecaudacion){
            case 1:
                archiD.listarRecaudacionAnual();
                break;
            case 2:
                archiD.listarRecaudacionMensual();
                break;
            case 3:
                archiD.listarRecaudacionPorCliente();
                break;
            case 4:
                archiD.listarRecaudacionPorProducto();
                break;
            case 5:
                archiD.listarProductosPorCategoria();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcRecaudacion != 0) system("pause");
    }while(opcRecaudacion != 0);
}

void Consulta_Producto(){
    system("cls");
    Nombre_Local();
    cout << "BUSQUEDA DE PRODUCTOS" << endl;
    cout << "1 - Buscar por ID" << endl;
    cout << "2 - Buscar por categoria" << endl;
    cout << "3 - Buscar por rango de precio" << endl;
    cout << "4 - Buscar por fecha de ingreso" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void Menu_Configuracion(){
    system("cls");
    Nombre_Local();
    cout << "           --------    CONFIGURACION  -----------" << endl << endl;
    cout << "1 - Realizar copia de seguridad" << endl;
    cout << "2 - Restaurar copia de seguridad" << endl;
    cout << "3 - Exportar datos" << endl;
    cout << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";

}

void Menu_Copia_Seguridad(){
    system("cls");
    Nombre_Local();
    cout << "REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - VENDEDORES" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

void Menu_Restaurar_Copia(){
    system("cls");
    Nombre_Local();
    cout << "RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - VENDEDORES" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

void Menu_Exportar(){
    system("cls");
    Nombre_Local();
    cout << "EXPORTAR ARCHIVOS CSV" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - VENDEDORES" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

void SubMenu_Copia_Seguridad(){
    int opcConfig;
    ArchivoProductos fileProd("productos.dat");
    ArchivoClientes fileCli("clientes.dat");
    Proveedor copia;
    ArchivoDetalle fileDet("detalle_ventas.dat");
    ArchivoVendedores fileVen("vendedores.dat");
    do{
        Menu_Copia_Seguridad();
        cin >> opcConfig;
        switch (opcConfig){
            case 1:
                ///COPIA SEGURIDAD PRODUCTO
                fileProd.Copia_Seguridad();
                break;
            case 2:
                ///COPIA SEGURIDAD CLIENTE
                fileCli.Copia_Seguridad();
                break;
            case 3:
                ///COPIA SEGURIDAD PROVEEDORES
                copia.Copia_Seguridad();
                break;
            case 4:
                ///COPIA SEGURIDAD VENTAS
                fileDet.Copia_Seguridad();
                break;
            case 5:
                ///COPIA SEGURIDAD VENDEDORES
                fileVen.Copia_Seguridad();
                break;
            case 6:{
                ///COPIA SEGURIDAD TODO
                fileProd.Copia_Seguridad();
                fileCli.Copia_Seguridad();
                copia.Copia_Seguridad();
                fileDet.Copia_Seguridad();
                fileVen.Copia_Seguridad();
            }
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcConfig != 0) system("pause");
    }while(opcConfig != 0);
}

void SubMenu_Restaurar_copia(){
    int opcConfig;
    ArchivoProductos fileProd("productos.dat");
    ArchivoClientes fileCli("clientes.dat");
    Proveedor copia;
    ArchivoDetalle fileDet("detalle_ventas.dat");
    ArchivoVendedores fileVen("vendedores.dat");
    do{
        Menu_Restaurar_Copia();
        cin >> opcConfig;
        switch (opcConfig){
            case 1:
                ///RESTAURAR COPIA PRODUCTO
                fileProd.Restaurar();
                break;
            case 2:
                ///RESTAURAR COPIA CLIENTE
                fileCli.Restaurar();
                break;
            case 3:
                ///RESTAURAR COPIA PROVEEDORES
                copia.Restaurar();
                break;
            case 4:
                ///RESTAURAR COPIA VENTAS
                fileDet.Restaurar();
                break;
            case 5:
                ///RESTAURAR COPIA VENDEDORES
                fileVen.Restaurar();
                break;
            case 6:{
                ///RESTAURAR COPIA TODO
                fileDet.Restaurar();
                copia.Restaurar();
                fileCli.Restaurar();
                fileProd.Restaurar();
                fileVen.Restaurar();
            }
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcConfig != 0) system("pause");
    }while(opcConfig != 0);
}

void SubMenu_Exportar(){
    int opcConfig;
    do{
        Menu_Exportar();
        cin >> opcConfig;
        switch (opcConfig){
            case 1:
                ///EXPORTAR PRODUCTO
                break;
            case 2:
                ///EXPORTAR CLIENTE
                break;
            case 3:
                ///EXPORTAR PROVEEDORES
                break;
            case 4:
                ///EXPORTAR VENTAS
                break;
            case 5:
                ///EXPORTAR Vendedores
                break;
            case 6:
                ///EXPORTAR TODO
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcConfig != 0) system("pause");
    }while(opcConfig != 0);
}

void SubmenuConfiguraciones(){
    int opcConfiguracion;
    do{
        Menu_Configuracion();
        cin >> opcConfiguracion;
        switch (opcConfiguracion){
            case 1:
                SubMenu_Copia_Seguridad();
                break;
            case 2:
                SubMenu_Restaurar_copia();
                break;
            case 3:
                SubMenu_Exportar();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                return;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
        }
        if(opcConfiguracion != 0) system("pause");
    }while(opcConfiguracion != 0);
}



#endif // FUNCIONES_H_INCLUDED
