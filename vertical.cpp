#include "vertical.h"
#include <QDebug>


vertical::vertical()
{

}

vertical::vertical(int fila, int columna) : estacion(fila,columna)
{
    this->tipo = "Vertical";
}

bool vertical::estacionColapsada(){
    vector<pair<int, int>> puntosConexion = this->getPuntosEntradaSalida();

    if (puntosConexion.size() > 2) {
        qDebug() << "// Error: Hay más de 2 puntos de conexión";
        return true;
    }

    if (puntosConexion.size() == 2 && puntosConexion[0].second != puntosConexion[1].second) {
        qDebug() << "Error: Los puntos tienen diferentes columnas";
        return true;
    }

    if (puntosConexion.size() == 1) {
        if(puntosConexion[0].second != this->getColumna()){
            qDebug() << "Error: No se respeto una conexion vertical";
            return true;
        }
    }

    if (puntosConexion.size() == 2) {
        if(puntosConexion[0].second != this->getColumna() || puntosConexion[1].second != this->getColumna()){
            qDebug() << "Error: No se respeto una conexion vertical";
            return true;
        }
    }

    return false;
}
