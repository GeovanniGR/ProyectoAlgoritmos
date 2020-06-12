/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aerolinea.cpp
 * Author: raquel
 * 
 * Created on 9 de junio de 2020, 20:09
 */

#include "Aerolinea_1.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Aerolinea::Aerolinea() {
}

Aerolinea::Aerolinea(string nombre,vector<Pais> paisOrigen, vector<PaisDestino> paisDestino) {
    this->nombre = nombre;
    this->paisOrigen=paisOrigen;
    this->paisDestino=paisDestino;
}//constructor sobrecargado

string Aerolinea::toString() {
//    stringstream s;
//    s << "Nombre: " << this->nombre;
//    return s.str();
}

void Aerolinea::setPaisDestino(vector<PaisDestino> paisDestino) {
    this->paisDestino = paisDestino;
}

void Aerolinea::setNombre(string nombre) {
    this->nombre = nombre;
}

vector<Pais> Aerolinea::getPaisOrigen() {
    return paisOrigen;
}



vector<PaisDestino> Aerolinea::getPaisDestino(){
    return paisDestino;
}

string Aerolinea::getNombre() {
    return nombre;
}



