/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pais.h
 * Author: raquel
 *
 * Created on 9 de junio de 2020, 22:13
 */

#ifndef PAIS_H
#define PAIS_H
#include <iostream>
#include <string>
using namespace std;
class Pais {
public:
    Pais();
    Pais(string pais);
    string GetPais() const {
        return pais;
    }

    void SetPais(string pais) {
        this->pais = pais;
    }

//    Pais(const Pais& orig);
//    virtual ~Pais();
private:
    string pais;
};

#endif /* PAIS_H */

