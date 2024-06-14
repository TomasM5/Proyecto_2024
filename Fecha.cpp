//Nombre: Tomas Manfredi
//TP Nº:
//EJ Nº:
/*Comentarios:
*/
#include<iostream>
#include<ctime>
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

Fecha Fecha::Hoy(){
    time_t t;
    struct tm *f;
    time (&t);
    f = localtime(&t);
    _Dia= f->tm_mday;
    _Mes= f->tm_mon+1;
    _Anio= f->tm_year+1900;
}
