/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegistrarUsuarioData.h
 * Author: gerald
 *
 */

#ifndef REGISTRARUSUARIODATA_H
#define REGISTRARUSUARIODATA_H

#include <vector>
#include "Usuario.h"

class RegistrarUsuarioData {
public:
    RegistrarUsuarioData();
    bool encotrarUsuario(Usuario* usuario);
    bool registrarUsuario(Usuario* usuario);
    Usuario* devolverUsuario(Usuario* usuario);
private:
    vector<Usuario*> vectorUsuario;
};

#endif /* REGISTRARUSUARIODATA_H */

