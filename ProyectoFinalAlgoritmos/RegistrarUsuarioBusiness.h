/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistrarUsuarioBusiness.h
 * Author: gerald
 *
 */

#ifndef REGISTRARUSUARIOBUSINESS_H
#define REGISTRARUSUARIOBUSINESS_H

#include "RegistrarUsuarioData.h"

class RegistrarUsuarioBusiness {
public:  
    static RegistrarUsuarioBusiness* getInstance();
    bool encotrarUsuario(Usuario* usuario);
    bool registrarUsuario(Usuario* usuario);

private:
    RegistrarUsuarioBusiness();
    RegistrarUsuarioData registrarUsuarioData;
    static RegistrarUsuarioBusiness* instance;
};


#endif /* REGISTRARUSUARIOBUSINESS_H */

