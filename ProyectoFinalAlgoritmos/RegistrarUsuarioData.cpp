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
}

bool RegistrarUsuarioData::registrarUsuario(Usuario* usuario) {
    this->vectorUsuario.push_back(usuario);
    return true;
}//true

bool RegistrarUsuarioData::encotrarUsuario(Usuario* usuario) {
    for (int i = 0; i < this->vectorUsuario.size(); i++) {
        if (vectorUsuario.at(i)->getNombre() == usuario->getNombre() &&
                //                vectorUsuario.at(i).getEdad().compare(usuario.getEdad()) == 0 &&
                vectorUsuario.at(i)->getGenero() == usuario->getGenero() &&
                //                vectorUsuario.at(i).getNumPasaporte().compare(usuario.getNumPasaporte()) == 0 &&
                vectorUsuario.at(i)->getNacionalidad() == usuario->getNacionalidad()) {
            return true;
        }//if
    }//for
    return false;
}//encotrarUsuario
