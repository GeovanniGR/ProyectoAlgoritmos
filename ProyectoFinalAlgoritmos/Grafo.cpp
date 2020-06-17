/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.cpp
 * Author: gerald
 * 
 * Created on 16 de junio de 2020, 04:29 PM
 */

#include "Grafo.h"

Grafo::Grafo() {
    p = NULL;
    p2 = NULL;

}

void Grafo::agregarNodo(string elemento) {
    Tnodo t, nuevo = new struct nodo;
    nuevo->nombre = elemento;
    nuevo->sgte = NULL;
    nuevo->ady = NULL;

    if (p == NULL) {
        p = nuevo;

    } else {
        t = p;
        while (t->sgte != NULL) {
            t = t->sgte;
        }
        t->sgte = nuevo;
    }
    cout << "Nodo ingresado: " << elemento << endl;
}//agregarNodo

void Grafo::agregarArista(Tnodo& aux, Tnodo& aux2, Tarista& nuevo) {
    Tarista q;
    if (aux->ady == NULL) {
        aux->ady = nuevo;
        nuevo->destino = aux;
    } else {
        q = aux->ady;
        while (q->sgte != NULL)
            q = q->sgte;
        nuevo->destino = aux2;
        q->sgte = nuevo;
    }
}//agregarArista

void Grafo::insertarArista(string ini, string fin) {
    Tarista nuevo = new struct arista;
    Tnodo aux, aux2;

    if (p == NULL) {
        return;
    }
    nuevo->sgte = NULL;
    aux = p;
    aux2 = p;
    while (aux2 != NULL) {
        if (aux2->nombre == fin) {
            break;
        }//if
        aux2 = aux2->sgte;
    }//while
    while (aux != NULL) {
        if (aux->nombre == ini) {
            agregarArista(aux, aux2, nuevo);
            return;
        }//if
        aux = aux->sgte;
    }//while
}//insertarArista

void Grafo::vaciarAristas(Tnodo& aux) {
    Tarista q, r;
    q = aux->ady;
    while (q->sgte != NULL) {
        r = q;
        q = q->sgte;
        delete(r);
    }//while
}//vaciarAristas

