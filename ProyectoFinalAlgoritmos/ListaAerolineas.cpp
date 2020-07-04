/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAerolineas.cpp
 * Author: geovanni
 * 
 * Created on 9 de junio de 2020, 09:59 AM
 */
#include "ListaAerolineas.h"
#include <iostream>
using namespace std;

ListaAerolineas* ListaAerolineas::getInstance() {
    if (instance == 0) {
        instance = new ListaAerolineas();
    }
    return instance;
}//getInstance

ListaAerolineas::ListaAerolineas() {
    this->lista = this->inicio = this->fin = NULL;
}//constructor

Aerolinea ListaAerolineas::firstInlist() {
    return lista->nombre;
}//firstInlist

bool ListaAerolineas::isEmpty() {
    return this->lista == NULL;
}//isEmpty

void ListaAerolineas::insert(Aerolinea v) {
    nodo* nuevo = new(struct nodo);
    nuevo->nombre = v;

    if (inicio == NULL) {
        inicio = nuevo;
        lista = nuevo;
        fin = nuevo;
        lista->siguiente = inicio;
        lista->anterior = inicio;
    }//else
    else {
        fin->siguiente = nuevo;
        nuevo->anterior = fin;
        nuevo->siguiente = inicio;
        fin = nuevo;
        inicio->anterior = fin;
        lista = nuevo;
    }//else 
}//insert

int ListaAerolineas::getSize() {
    ptrLista aux = lista;
    int contador = 0;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    } else {
        do {
            contador++;
            aux = aux->siguiente;

        } while (aux != lista);
    }
    return contador;
}//getSize

void ListaAerolineas::showElements() {

    ptrLista aux = lista;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    } else {
        do {
            //cout << "Elemento de la lista: " << aux->nombre << endl;
            aux = aux->siguiente;

        } while (aux != lista);
    }
}//showElements

void ListaAerolineas::anular() {
    this->lista = NULL;
}//anular

string ListaAerolineas::resultado(string v) {
    int banderilla = 0;
    if (isEmpty()) {
       
    }
    ptrLista aux = lista;
    ptrLista aux1 = lista;
    do {
        if (aux->nombre.getNombre().find(v) != string::npos) {
            banderilla = 1;
            aux1->nombre = aux->nombre;
            aux = aux->siguiente; //cambia para salir del if
            return aux1->nombre.getNombre();
        } else {
            aux = aux->siguiente;
            //            pos++;
        }
    } while (aux != lista);
    if (banderilla == 0)
    return "";
}

vector<PaisDestino> ListaAerolineas::paisesD(string v) {
        int banderilla = 0;
    if (isEmpty()) {
       
    }
    ptrLista aux = lista;
    ptrLista aux1 = lista;
    do {
        if (aux->nombre.getNombre().find(v) != string::npos) {
            banderilla = 1;
            aux1->nombre = aux->nombre;
            aux = aux->siguiente; //cambia para salir del if
            return aux1->nombre.getPaisDestino();
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);
}//paisesD

vector<Pais> ListaAerolineas::paisesO(string v) {
        int banderilla = 0;
    if (isEmpty()) {
       
    }
    ptrLista aux = lista;
    ptrLista aux1 = lista;
    do {
        if (aux->nombre.getNombre().find(v) != string::npos) {
            banderilla = 1;
            aux1->nombre = aux->nombre;
            aux = aux->siguiente; //cambia para salir del if
            return aux1->nombre.getPaisOrigen();
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);
}//paisesO (Pais origen)

string ListaAerolineas::showNext(string v) {
    if (isEmpty()) {
        return "vacida";
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre.getNombre().find(v)!=string::npos) {
            aux = aux->siguiente; //cambia para salir del if
            return aux->nombre.getNombre();
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);

}//showNext

string ListaAerolineas::showPrevious(string v) {
    if (isEmpty()) {
        return "vacida";
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre.getNombre().find(v)!=string::npos) {
            aux = aux->anterior; //cambia para salir del if
            return aux->nombre.getNombre();
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);
}//showPrevious

ListaAerolineas* ListaAerolineas::instance = 0;