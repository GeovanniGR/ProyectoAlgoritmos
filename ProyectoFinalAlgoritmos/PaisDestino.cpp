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
}

PaisDestino::PaisDestino(string nombrePais) {
    this->nombrePais=nombrePais;
}

//setter&&getter

void PaisDestino::SetNombrePais(string nombrePais) {
    this->nombrePais = nombrePais;
}

string PaisDestino::GetNombrePais() {
    return this->nombrePais;
}


//PaisDestino::PaisDestino(const PaisDestino& orig) {
//}
//
//PaisDestino::~PaisDestino() {
//}

