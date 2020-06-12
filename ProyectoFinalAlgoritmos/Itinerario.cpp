/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Itinerario.cpp
 * Author: raquel
 * 
 * Created on 10 de junio de 2020, 16:02
 */

#include "Itinerario.h"

Itinerario::Itinerario() {
}

Itinerario::Itinerario(Aerolinea aerolinea, Pais paisorigen, PaisDestino paisDestino) {
    this->aerolinea= aerolinea;
    this->paisorigen=paisorigen;
    this->paisdestino = paisDestino;
    this->cantEspacios=0;
    this->horariosSalida;
    this->horarioLLegada;
}

string Itinerario::toString() {
    stringstream s;
    s<<this->aerolinea.getNombre()<<"\n"<<this->paisorigen.GetPais()<<"\n"<<this->paisdestino.GetNombrePais()<<"\n"<<this->cantEspacios<<"\n";
    return s.str();
}


//setter&&getter

void Itinerario::setPaisdestino(PaisDestino paisdestino) {
    this->paisdestino = paisdestino;
}

PaisDestino Itinerario::getPaisdestino() {
    return paisdestino;
}

Aerolinea Itinerario::GetAerolinea(){
    return aerolinea;
}

int Itinerario::GetCantEspacios() {
    return cantEspacios;
}

Cola Itinerario::GetHorariosSalida() {
    return horariosSalida;
}

Cola Itinerario::GetHorariosLlegada() {
    return horarioLLegada;
}

Pais Itinerario::GetPaisorigen() {
    return paisorigen;
}

void Itinerario::SetAerolinea(Aerolinea aerolinea) {
    this->aerolinea = aerolinea;
}

void Itinerario::SetCantEspacios(int cantEspacios) {
    this->cantEspacios = cantEspacios;
}

void Itinerario::SetPaisorigen(Pais paisorigen) {
    this->paisorigen = paisorigen;
}

void Itinerario::SetHorariosSalida(Cola horarios) {
    this->horariosSalida = horarios;
}

void Itinerario::SetHorariosLlegada(Cola horarios) {
    this->horarioLLegada = horarios;
}

//Itinerario::Itinerario(const Itinerario& orig) {
//}
//
//Itinerario::~Itinerario() {
//}

