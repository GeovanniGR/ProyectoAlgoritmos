/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAerolineas.h
 * Author: geovanni
 *
 * Created on 9 de junio de 2020, 09:58 AM
 */

#ifndef LISTAAEROLINEAS_H
#define LISTAAEROLINEAS_H

#include <string>

#include "Aerolinea_1.h"
#include "Pais.h"
#include "PaisDestino.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ListaAerolineas {

    struct nodo {
        Aerolinea nombre;
        struct nodo *siguiente, *anterior;
    };
    typedef nodo *ptrLista;
public:
    static ListaAerolineas* getInstance();
    int getSize();
    int getPosition(string v);
    void showElements();
    void anular();
    bool isEmpty();

    void insert(Aerolinea v);
    void borrar(string v);
    bool exist(string v);
    string resultado(string v);
    vector<Pais> paisesO(string v);
    vector <PaisDestino> paisesD(string v);
    string showNext(string v);
    string showPrevious(string v);
    Aerolinea firstInlist();

private:
    ListaAerolineas();
    static ListaAerolineas* instance;
    ptrLista lista;
    nodo *inicio;
    nodo *fin;
};


#endif /* LISTAAEROLINEAS_H */

