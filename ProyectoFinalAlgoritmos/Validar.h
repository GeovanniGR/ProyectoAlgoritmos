/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Validar.h
 * Author: gerald
 *
 * Created on 8 de junio de 2020, 08:12 PM
 */

#ifndef VALIDAR_H
#define VALIDAR_H

#include <string>

using namespace std;

class Validar {
public:
    Validar();
    static bool validar_Es_Numero(string numero);
    static bool validar_Es_Letra(string palabra);
    
private:

};

#endif /* VALIDAR_H */

