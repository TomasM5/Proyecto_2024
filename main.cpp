#include <iostream>

using namespace std;
#include "Headers.h"
#include "Funciones.h"

int main() {
    int opc;

    do{
        Menu_Principal();
        cin >> opc;
        switch(opc){
            case 1:
                SubMenuVentas();
                system("pause");
                break;
            case 2:
                SubMenuClientes();
                break;
            case 3:
                Menu_Inventario();
                system("pause");
                break;
            case 4:
                SubMenuVendedores();
                system("pause");
                break;
            case 5:
                SubmenuProveedores();
                system("pause");
                break;
            case 6:
                Menu_Configuracion();
                system("pause");
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                system("pause");
                break;
                }
    }while (opc!=0);

    return 0;
}
