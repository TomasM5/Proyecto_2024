//Nombre: Tomas Manfredi
//TP Nº:
//EJ Nº:
/*Comentarios:
*/
#include<iostream>
using namespace std;
#include "Fecha.h"


Fecha::Fecha() {
    setDia(1);
    setMes(1);
    setAnio(1970);
}

Fecha::Fecha(int d, int m, int a) {
    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::Cargar () {
    int d, m, a;

    cout << "Dia: ";
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Anio: ";
    cin >> a;

    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::MostrarNumero () {
    cout << getDia() << "/" << getMes() << "/" << getAnio();
}

