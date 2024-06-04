#include <iostream>

using namespace std;
#include "Headers.h"
#include "Funciones.h"

int main() {
    int opc;

    do{
        Menu_Principal();
        cin >> opc;
        switch (opc) {
    case 1:
        Menu_Ventas();
        system("pause");
        break;
    case 2:
        Menu_Clientes();
        system("pause");
        break;
    case 3:
        Menu_Inventario();
        system("pause");
        break;
    case 4:
        break;
    case 5:
        Menu_Configuracion();
        system("pause");
        break;
    case 6:
        break;

        case 0:
        break;
        }
    }while (opc!=0);


    return 0;
}
