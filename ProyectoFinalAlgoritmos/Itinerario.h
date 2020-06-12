/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.h
 * Author: raquel
 *
 * Created on 10 de junio de 2020, 16:02
 */

#ifndef ITINERARIO_H
#define ITINERARIO_H
#include <iostream>
#include <string>
#include <sstream>
#include "Aerolinea_1.h"
#include "Pais.h"
#include "Cola.h"
#include "PaisDestino.h"
using namespace std;

class Itinerario {
public:
    Itinerario();
    Itinerario(Aerolinea aerolinea, Pais paisorigen, PaisDestino paisDestino);

    string toString();
    //setter&getter
    Aerolinea getAerolinea();

    void setAerolinea(Aerolinea aerolinea);

    int getCantEspacios();

    void setCantEspacios(int cantEspacios);

    Cola getHorariosSalida();

    void setHorariosSalida(Cola horarios);

    Cola getHorariosLlegada();

    void setHorariosLlegada(Cola horarios);

    Pais getPaisorigen();

    void setPaisorigen(Pais paisorigen);
    PaisDestino getPaisdestino();

    void setPaisdestino(PaisDestino paisdestino);


private:
    Aerolinea aerolinea;

    Pais paisorigen; //pais origen

    PaisDestino paisdestino; //paisDestino

    int cantEspacios;

    Cola horariosSalida;
    Cola horarioLLegada;
};

#endif /* ITINERARIO_H */

