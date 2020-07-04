/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrador.cpp
 * Author: raquel
 * 
 * Created on 2 de julio de 2020, 16:51
 */

#include "Administrador.h"

Administrador::Administrador() {
    this->nombre = "master";
    this->password = 147;
}//Administrador

//setter&&getter
void Administrador::SetPassword(int password){
    this->password= password;
}//SetPassword

void Administrador::SetNombre(string nombre) {
    this->nombre = nombre;
}//SetNombre

int Administrador::GetPassword() {
    return password;
}//GetPassword

string Administrador::GetNombre() {
    return nombre;
}//GetNombre
