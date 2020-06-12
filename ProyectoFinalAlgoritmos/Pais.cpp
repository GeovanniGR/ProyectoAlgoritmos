/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.cpp
 * Author: raquel
 * 
 * Created on 9 de junio de 2020, 22:13
 */

#include "Pais.h"

Pais::Pais() {
}//constructor

Pais::Pais(string pais) {
    this->pais = pais;
}//constructor

//setter&&getter

void Pais::setPais(string pais) {
    this->pais = pais;
}//setPais

string Pais::getPais() {
    return pais;
}//getPais
