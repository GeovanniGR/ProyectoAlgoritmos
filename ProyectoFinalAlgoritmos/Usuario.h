/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.h
 * Author: gerald
 *
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
public:
    Usuario(string nombre, int edad, string genero, int numPasaporte, string nacionalidad);
    Usuario(string nombre);
    Usuario(string nombre, int numPasaporte);
    
    void setNombre(string nombre);
    string getNombre();
    
    void setEdad(int edad);
    int getEdad();
    
    void setGenero(string genero);
    string getGenero();
    
    void setNumPasaporte(int numPasaporte);
    int getNumPasaporte();
    
    void setNacionalidad(string nacionalidad);
    string getNacionalidad();

    string toString();
    
private:

    string nombre;
    int edad;
    string genero;
    int numPasaporte;
    string nacionalidad;
};

#endif /* USUARIO_H */

