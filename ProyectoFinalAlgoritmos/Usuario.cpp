/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Usuario.cpp
 * Author: gerald
 * 
 * Created on 8 de junio de 2020, 05:32 PM
 */

#include "Usuario.h"
#include <iostream>
#include <sstream>

Usuario::Usuario(string nombre, int edad, string genero, int numPasaporte, string nacionalidad) {
    this->nombre = nombre;
    this->edad = edad;
    this->genero = genero;
    this->numPasaporte = numPasaporte;
    this->nacionalidad = nacionalidad;
}//constructor

Usuario::Usuario(string nombre) {
    this->nombre = nombre;
}//constructor

Usuario::Usuario(string nombre, int numPasaporte) {
    this->nombre = nombre;
    this->numPasaporte = numPasaporte;
}//constructor

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}//setNombre

string Usuario::getNombre() {
    return nombre;
}//getNombre

void Usuario::setEdad(int edad) {
    this->edad = edad;
}//setEdad

int Usuario::getEdad() {
    return edad;
}//getEdad

void Usuario::setGenero(string genero) {
    this->genero = genero;
}//setGenero

string Usuario::getGenero() {
    return genero;
}//getGenero

void Usuario::setNumPasaporte(int numPasaporte) {
    this->numPasaporte = numPasaporte;
}//setNumPasaporte

int Usuario::getNumPasaporte() {
    return numPasaporte;
}//getNumPasaporte

void Usuario::setNacionalidad(string nacionalidad) {
    this->nacionalidad = nacionalidad;
}//setNacionalidad

string Usuario::getNacionalidad() {
    return nacionalidad;
}//getNacionalidad

string Usuario::toString() {
    stringstream s;
    s << "Nombre: " << this->nombre << ", Edad: " << this->edad << ", Genero: " <<
            this->genero << ", Nacionalidad: " << this->nacionalidad << ", Numero pasporte: " << this->numPasaporte << "." << endl;
    return s.str();
}//toString