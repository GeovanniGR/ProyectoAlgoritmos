/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaisDestino.cpp
 * Author: raquel
 * 
 * Created on 10 de junio de 2020, 16:28
 */

#include "PaisDestino.h"

PaisDestino::PaisDestino() {
}//constructor

PaisDestino::PaisDestino(string nombrePais) {
    this->nombrePais = nombrePais;
}//constructor

//setter&&getter

void PaisDestino::setNombrePais(string nombrePais) {
    this->nombrePais = nombrePais;
}//setNombrePais

string PaisDestino::getNombrePais() {
    return this->nombrePais;
}//getNombrePais
