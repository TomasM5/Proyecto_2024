#ifndef FECHA_H
#define FECHA_H


class Fecha {
    public:
        Fecha();
        Fecha(int d, int m, int a);
        void Cargar ();
        void MostrarNumero ();
        void MostrarTexto ();

        void setDia(int val) { _Dia = val; }
        void setMes(int val) { _Mes = val; }
        void setAnio(int val) { _Anio = val; }
        int getDia() { return _Dia; }
        int getMes() { return _Mes; }
        int getAnio() { return _Anio; }

        bool operator==(const Fecha& otra) const {
            return _Dia == otra._Dia && _Mes == otra._Mes && _Anio == otra._Anio;
        }

    protected:

    private:
        int _Dia;
        int _Mes;
        int _Anio;
};


#endif // FECHA_H
