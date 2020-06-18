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

bool Grafo::isEmpty() {
    return p == NULL;
}

Grafo* Grafo::getInstance() {
    if (instance == 0) {
        instance = new Grafo();
    }
    return instance;
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
        nuevo->destino = aux2;
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

void Grafo::eliminarNodo(string eliminar) {
    string var;
    Tnodo aux, ant;
    aux = p;
    cout << "ELIMINAR UN NODO\n";
    if (p == NULL) {
        cout << "GRAFO VACIO...!!!!";
        return;
    }
    var = eliminar;

    while (aux != NULL) {
        if (aux->nombre == var) {
            if (aux->ady != NULL)
                vaciarAristas(aux);

            if (aux == p) {
                p = p->sgte;
                delete(aux);
                cout << "NODO ELIMINADO...!!!!";
                return;
            } else {
                ant->sgte = aux->sgte;
                delete(aux);
                cout << "NODO ELIMINADO...!!!!";
                return;
            }
        } else {
            ant = aux;
            aux = aux->sgte;
        }
    }
}

void Grafo::eliminarArista(string ini, string fin) {
    Tnodo aux, aux2;
    Tarista q, r;
    cout << "\n ELIMINAR ARISTA\n";
    aux = p;
    aux2 = p;
    while (aux2 != NULL) {
        if (aux2->nombre == fin) {
            break;
        } else
            aux2 = aux2->sgte;
    }
    while (aux != NULL) {
        if (aux->nombre == ini) {
            q = aux->ady;
            while (q != NULL) {
                if (q->destino == aux2) {
                    if (q == aux->ady)
                        aux->ady = aux->ady->sgte;
                    else
                        r->sgte = q->sgte;
                    delete(q);
                    cout << "ARISTA  " << aux->nombre << "----->" << aux2->nombre << " ELIMINADA.....!!!!";
                    return;
                }
            }
            r = q;
            q = q->sgte;
        }
        aux = aux->sgte;
    }
}

void Grafo::mostrarGrafo() {
    Tnodo ptr;
    Tarista ar;
    ptr = p;
    cout << "NODO|LISTA DE ADYACENCIA\n";

    while (ptr != NULL) {
        cout << "   " << ptr->nombre << "|";
        if (ptr->ady != NULL) {
            ar = ptr->ady;
            while (ar != NULL) {
                cout << " " << ar->destino->nombre;
                ar = ar->sgte;
            }

        }
        ptr = ptr->sgte;
        cout << endl;
    }
}

vector<string> Grafo::arista(string nodo) {
    Tnodo aux;
    Tarista ar;
    vector<string> aristas;
    //char var;
    //cin>>var;
    aux = p;
    while (aux != NULL) {
        if (aux->nombre == nodo) {
            if (aux->ady == NULL) {
                
            } else {
//                cout << "NODO|LISTA DE ADYACENCIA\n";
//                cout << "   " << aux->nombre << "|";
                ar = aux->ady;

                while (ar != NULL) {
                    aristas.push_back(ar->destino->nombre);
                    ar = ar->sgte;
                }
                return aristas;
            }
        } else
            aux = aux->sgte;
    }
}

void Grafo::mostrarAristas(string nodo) {
    Tnodo aux;
    Tarista ar;
    //char var;
    cout << "MOSTRAR ARISTAS DE NODO\n";
    //cin>>var;
    aux = p;
    while (aux != NULL) {
        if (aux->nombre == nodo) {
            if (aux->ady == NULL) {
                cout << "EL NODO NO TIENE ARISTAS...!!!!";
                return;
            } else {
                cout << "NODO|LISTA DE ADYACENCIA\n";
                cout << "   " << aux->nombre << "|";
                ar = aux->ady;

                while (ar != NULL) {
                    cout << ar->destino->nombre << " ";
                    ar = ar->sgte;
                }
                cout << endl;
                return;
            }
        } else
            aux = aux->sgte;
    }
}

void Grafo::setNombresNodos(vector<Pais> nombresNodos) {
    this->nombresNodos = nombresNodos;
}

vector<Pais> Grafo::getNombresNodos() {
    return nombresNodos;
}

bool Grafo::existe(string nodo) {
    Tnodo aux;
    Tarista ar;
    aux = p;
    while (aux != NULL) {
        if (aux->nombre == nodo) {
            if (aux->ady == NULL) {
                return false;
            } else {
                ar = aux->ady;
                while (ar != NULL) {
                    ar = ar->sgte;
                }
                return true;
            }
        } else
            aux = aux->sgte;
    }
}

void Grafo::setPaisDes(vector<PaisDestino> paisDes) {
    this->paisDes = paisDes;
}

vector<PaisDestino> Grafo::getPaisDes() {
    return paisDes;
}



Grafo* Grafo::instance = 0;