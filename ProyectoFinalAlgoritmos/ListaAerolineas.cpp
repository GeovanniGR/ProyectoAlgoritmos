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
}

ListaAerolineas::ListaAerolineas() {
    this->lista = this->inicio = this->fin = NULL;
}//constructor

string ListaAerolineas::firstInlist() {
    return lista->nombre;
}//firstInlist

bool ListaAerolineas::isEmpty() {
    return this->lista == NULL;
}//isEmpty

void ListaAerolineas::insert(string v) {
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

int ListaAerolineas::getPosition(string v) {
    int pos = 0;
    int banderilla = 0;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre == v) {
            banderilla = 1;
            break;

        } else {
            aux = aux->siguiente;
            pos++;
        }
    } while (aux != lista);
    if (banderilla == 0)
        cout << "no encontrado";
    return pos + 1;
}//getPosition

void ListaAerolineas::showElements() {

    ptrLista aux = lista;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    } else {
        do {
            cout << "Elemento de la lista: " << aux->nombre << endl;
            aux = aux->siguiente;

        } while (aux != lista);
    }
}//showElements

void ListaAerolineas::anular() {
    this->lista = NULL;
}//anular

bool ListaAerolineas::exist(string v) {
    int banderilla = 0;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre.find(v) != string::npos) {
            banderilla = 1;
            aux = aux->siguiente; //cambia para salir del if
            return true;
        } else {
            aux = aux->siguiente;
            //            pos++;
        }
    } while (aux != lista);
    if (banderilla == 0)
        cout << "\nno encontrado" << endl;
    return false;
}//exist

void ListaAerolineas::borrar(string v) {
    int n = 0;
    ptrLista nuevaLista, nodoSinBorrar;
    nuevaLista = new (struct nodo);
    nuevaLista = NULL;

    ptrLista aux = lista;
    ptrLista anterior = new (struct nodo);
    anterior = NULL;
    int banderilla = 0;
    if (isEmpty()) {
        cout << "esta vacia" << endl;
    }
    do {
        if (aux->nombre != v) {
            nodoSinBorrar = new (struct nodo);
            nodoSinBorrar->nombre = aux->nombre;
            nodoSinBorrar->siguiente = nuevaLista;
            nuevaLista = nodoSinBorrar;
            aux = aux->siguiente;
            banderilla = 1;
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);
    lista = nuevaLista;
}//borrar

string ListaAerolineas::showNext(string v) {
    if (isEmpty()) {
        return "esta vacia";
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre.find(v) != string::npos) {
            aux = aux->siguiente; //cambia para salir del if
            return aux->nombre;
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);

}//showNext

string ListaAerolineas::showPrevious(string v) {
    if (isEmpty()) {
        return "esta vacia";
    }
    ptrLista aux = lista;
    do {
        if (aux->nombre.find(v) != string::npos) {
            aux = aux->anterior; //cambia para salir del if
            return aux->nombre;
        } else {
            aux = aux->siguiente;
        }
    } while (aux != lista);

}//showPrevious

ListaAerolineas* ListaAerolineas::instance = 0;