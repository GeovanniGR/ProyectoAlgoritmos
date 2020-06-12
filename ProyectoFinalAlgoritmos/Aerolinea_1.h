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
#include <vector>
#include "Pais.h"
#include "PaisDestino.h"
using namespace std;

class Aerolinea {
public:
    Aerolinea();
    Aerolinea(string nombre, vector<Pais> paisOrigen, vector<PaisDestino> paisDestino);
    string toString();

    //setter&getter
    string getNombre();
    void setNombre(string nombre);
    vector<PaisDestino> getPaisDestino();
    void setPaisDestino(vector<PaisDestino> paisDestino);
    vector<Pais> getPaisOrigen();

private:
    string nombre;
    vector<Pais> paisOrigen;
    vector<PaisDestino> paisDestino;
};

#endif /* AEROLINEA_H */

