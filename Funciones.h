#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <cstring>

void Nombre_Local () {
    cout << "           --------    DECORACIONES LUZ TORMENTOSA   ------" << endl << endl;
}
void Menu_Principal (){
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

    //cout << "5- Proveedores" << endl;
    // reportes de compras del local?

    cout << "- Configuracion" << endl;
    // ->  cargar proveedor,copias de seguridad

    cout << "0 - Salir";

    cout << endl << endl;
    cout << "Ingrese la opcion: ";

}

void Menu_Ventas () {
    system("cls");
    Nombre_Local();
    cout << "           -------     VENTAS   ----------" << endl << endl;
    cout << "1 - Registrar Venta" << endl;
    cout << "2 - Historial de ventas" << endl; // listado de venta por fecha, ¿incluir consulta aca? puede solicitar fecha y de lo contrario mostrar todo
    cout << "3 - Buscar ID" << endl;
    cout << "4 - Ventas por cliente" << endl;
    cout << "5 - Ventas por producto" << endl;
    cout << "0 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
    //  producto mas vendido?

}

void Menu_Clientes () {
    system("cls");
    Nombre_Local();
    cout << "           -------     CLIENTES   ----------" << endl << endl;
    cout << "1 - Registrar cliente nuevo" << endl;
    cout << "2 - Lista de clientes" << endl;
    cout << "3 - Buscar cliente" << endl;
    cout << "4 - Buscar DNI" << endl; // consulta de cliente por dni
    cout << "5 - Buscar nombre" << endl;
    cout << "6 - Volver al menu principal" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
    //consulta por tipo de consumidor?
}

void Lista_Clientes() {
    system("cls");
    Nombre_Local();
    cout << "LISTAR CLIENTES" << endl;
    cout << "Elija el orden" << endl;
    cout << "1 - Por apellido" << endl;
    cout << "2 - Por numero de registro" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";
}

void Menu_Inventario() {
    system("cls");
    Nombre_Local();
    cout << "           --------    INVENTARIO  -----------" << endl << endl;
    cout << "1 - Mostrar inventario" << endl;
    cout << "2 - Buscar producto" << endl;
    cout << "3 - Nuevo producto" << endl;
    cout << "4 - Compra de stock" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";

}

void Lista_Inventario() {
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

void Consulta_Producto() {
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

void Menu_Configuracion () {
    system("cls");
    Nombre_Local();
    cout << "           --------    CONFIGURACION  -----------" << endl << endl;
    cout << "1 - Realizar copia de seguridad" << endl;
    cout << "2 - Restaurar copia de seguridad" << endl;
    cout << "3 - Exportar datos" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion: ";

}

void Menu_Copia_Seguridad() {
    cout << "REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - CATEGORIAS" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

void Menu_Restaurar_Copia () {
    cout << "RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - CATEGORIAS" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

void Menu_Exportar() {
    cout << "EXPORTAR ARCHIVOS CSV" << endl;
    cout << "-------------------------------------" << endl;
    cout << "1 - PRODUCTOS" << endl;
    cout << "2 - CLIENTES" << endl;
    cout << "3 - PROVEEDORES" << endl;
    cout << "4 - VENTAS" << endl;
    cout << "5 - CATEGORIAS" << endl;
    cout << "6 - TODOS LOS ARCHIVOS" << endl;
    cout << "-------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "OPCION: ";
}

#endif // FUNCIONES_H_INCLUDED
