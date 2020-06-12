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
}//constructor

Itinerario::Itinerario(Aerolinea aerolinea, Pais paisorigen, PaisDestino paisDestino) {
    this->aerolinea = aerolinea;
    this->paisorigen = paisorigen;
    this->paisdestino = paisDestino;
    this->cantEspacios = 0;
    this->horariosSalida;
    this->horarioLLegada;
}//constructor

string Itinerario::toString() {
    stringstream s;
    s << this->aerolinea.getNombre() << "\n" << this->paisorigen.getPais() << "\n" << this->paisdestino.getNombrePais() << "\n" << this->cantEspacios << "\n";
    return s.str();
}//toString

//setter&&getter

void Itinerario::setPaisdestino(PaisDestino paisdestino) {
    this->paisdestino = paisdestino;
}//setPaisdestino

PaisDestino Itinerario::getPaisdestino() {
    return paisdestino;
}//getPaisdestino

Aerolinea Itinerario::getAerolinea() {
    return aerolinea;
}//getAerolinea

int Itinerario::getCantEspacios() {
    return cantEspacios;
}//getCantEspacios

Cola Itinerario::getHorariosSalida() {
    return horariosSalida;
}//getHorariosSalida

Cola Itinerario::getHorariosLlegada() {
    return horarioLLegada;
}//getHorariosLlegada

Pais Itinerario::getPaisorigen() {
    return paisorigen;
}//getPaisorigen

void Itinerario::setAerolinea(Aerolinea aerolinea) {
    this->aerolinea = aerolinea;
}//setAerolinea

void Itinerario::setCantEspacios(int cantEspacios) {
    this->cantEspacios = cantEspacios;
}//setCantEspacios

void Itinerario::setPaisorigen(Pais paisorigen) {
    this->paisorigen = paisorigen;
}//setPaisorigen

void Itinerario::setHorariosSalida(Cola horarios) {
    this->horariosSalida = horarios;
}//setHorariosSalida

void Itinerario::setHorariosLlegada(Cola horarios) {
    this->horarioLLegada = horarios;
}//setHorariosLlegada
