/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrador.h
 * Author: raquel
 *
 * Created on 2 de julio de 2020, 16:51
 */

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include <iostream>
using namespace std;
class Administrador {
public:
    Administrador();
    
    string GetNombre();

    void SetNombre(string nombre);

    int GetPassword();

    void SetPassword(int password);
       
//    virtual ~Administrador();
private:
    string nombre;
    int password;
};

#endif /* ADMINISTRADOR_H */

