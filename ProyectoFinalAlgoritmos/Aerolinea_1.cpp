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

#include "Aerolinea.h"
#include <iostream>
#include <string>
using namespace std;
Aerolinea::Aerolinea() {
}

Aerolinea::Aerolinea(string nombre) {
    this->nombre = nombre;
}//constructor sobrecargado

string Aerolinea::toString() {
//    stringstream s;
//    s << "Nombre: " << this->nombre;
//    return s.str();
}



