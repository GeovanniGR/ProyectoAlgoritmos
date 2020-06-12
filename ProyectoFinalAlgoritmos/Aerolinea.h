/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Aerolinea.h
 * Author: raquel
 *
 * Created on 9 de junio de 2020, 20:09
 */

#ifndef AEROLINEA_H
#define AEROLINEA_H
#include <iostream>
#include <string>
using namespace std;
class Aerolinea {
public:
    Aerolinea();
    Aerolinea(string nombre);
    string toString();
   
    //setter&getter
    string getNombre() const;

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

//    Aerolinea(const Aerolinea& orig);
//    virtual ~Aerolinea();
private:
    string nombre;
};

#endif /* AEROLINEA_H */

