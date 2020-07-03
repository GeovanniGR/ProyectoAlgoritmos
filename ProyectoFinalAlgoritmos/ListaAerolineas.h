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
using namespace std;

class ListaAerolineas {

    struct nodo {
        string nombre;
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

    void insert(string v);
    void borrar(string v);
    bool exist(string v);
    string showNext(string v);
    string showPrevious(string v);
    string firstInlist();

private:
    ListaAerolineas();
    static ListaAerolineas* instance;
    ptrLista lista;
    nodo *inicio;
    nodo *fin;
};


#endif /* LISTAAEROLINEAS_H */

