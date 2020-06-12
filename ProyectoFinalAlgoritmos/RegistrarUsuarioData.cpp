/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistrarUsuarioData.cpp
 * Author: gerald
 * 
 */

#include "RegistrarUsuarioData.h"
#include "Usuario.h"
#include <iostream>

RegistrarUsuarioData::RegistrarUsuarioData() {
}//constructor

bool RegistrarUsuarioData::registrarUsuario(Usuario* usuario) {
    this->vectorUsuario.push_back(usuario);
    return true;
}//registrarUsuario

bool RegistrarUsuarioData::encotrarUsuario(Usuario* usuario) {
    for (int i = 0; i < this->vectorUsuario.size(); i++) {
        if (vectorUsuario.at(i)->getNumPasaporte() == usuario->getNumPasaporte()) {
            return true;
        }//if
    }//for
    return false;
}//encotrarUsuario
