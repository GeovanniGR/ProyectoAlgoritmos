/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PaisDestino.h
 * Author: raquel
 *
 * Created on 10 de junio de 2020, 16:28
 */

#ifndef PAISDESTINO_H
#define PAISDESTINO_H
#include <iostream>
#include <string>
using namespace std;
class PaisDestino {
public:
    PaisDestino();
    
    PaisDestino(string nombrePais);
    
    
    //setter&getter
    string GetNombrePais() ;

    void SetNombrePais(string nombrePais);

//    PaisDestino(const PaisDestino& orig);
//    virtual ~PaisDestino();
private:
    string nombrePais;
};

#endif /* PAISDESTINO_H */

