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
}//constructor

Aerolinea::Aerolinea(string nombre, vector<Pais> paisOrigen, vector<PaisDestino> paisDestino) {
    this->nombre = nombre;
    this->paisOrigen = paisOrigen;
    this->paisDestino = paisDestino;
}//constructor sobrecargado

string Aerolinea::toString() {
    //    stringstream s;
    //    s << "Nombre: " << this->nombre;
    //    return s.str();
}//toString

void Aerolinea::setPaisDestino(vector<PaisDestino> paisDestino) {
    this->paisDestino = paisDestino;
}//setPaisDestino

void Aerolinea::setNombre(string nombre) {
    this->nombre = nombre;
}//setNombre

string Aerolinea::getNombre() {
    return this->nombre;
}//getNombre

vector<Pais> Aerolinea::getPaisOrigen() {
    return paisOrigen;
}//getPaisOrigen

vector<PaisDestino> Aerolinea::getPaisDestino() {
    return paisDestino;
}//getPaisDestino
