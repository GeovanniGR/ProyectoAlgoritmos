/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistrarUsuarioBusiness.cpp
 * Author: gerald
 * 
 * Created on 9 de junio de 2020, 09:08 AM
 */

#include "RegistrarUsuarioBusiness.h"

RegistrarUsuarioBusiness::RegistrarUsuarioBusiness() {
}

RegistrarUsuarioBusiness* RegistrarUsuarioBusiness::getInstance() {
    if (instance == 0) {
        instance = new RegistrarUsuarioBusiness();
    }
    return instance;
}

bool RegistrarUsuarioBusiness::registrarUsuario(Usuario* usuario) {
    bool registrado = false;
    if (registrarUsuarioData.registrarUsuario(usuario)) {
        registrado = true;
    }//if
    return registrado;
}//registrarUsuario

bool RegistrarUsuarioBusiness::encotrarUsuario(Usuario* usuario) {
    return this->registrarUsuarioData.encotrarUsuario(usuario);
}//encotrarUsuario
RegistrarUsuarioBusiness* RegistrarUsuarioBusiness::instance = 0;