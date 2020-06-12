/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaIniciarSesion.h
 * Author: gerald
 *
 * Created on 8 de junio de 2020, 04:48 PM
 */

#ifndef VENTANAINICIARSESION_H
#define VENTANAINICIARSESION_H

#include "gtkmm.h"
#include "RegistrarUsuarioBusiness.h"
#include "VentanaEscogerAerolinea.h"

using namespace std;

class VentanaIniciarSesion : public Gtk::Window {
public:
    VentanaIniciarSesion();

    void init();
    void accionIniciarSesion(Usuario* usuario);
    void iniciarSesion();
    void cerrarVentanaAerolineas();

    Gtk::Fixed fixed;

    Gtk::Button btnIniciarSesion;
    Gtk::Button btnEscogerVuelo;

    Gtk::Entry entryNombre;
    Gtk::Entry entryNumeroPasaporte;


    Gtk::Label lblNombre;
    Gtk::Label lblNumeroPasaporte;

    vector<Usuario*> vectorUsuario;
    VentanaEscogerAerolinea* ventanaEscogerAerolineas;

private:
    RegistrarUsuarioBusiness* registrarUsuarioBusiness;

};

#endif /* VENTANAINICIARSESION_H */
