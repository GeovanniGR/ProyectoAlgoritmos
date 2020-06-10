/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaRegistrar.h
 * Author: gerald
 *
 * Created on 8 de junio de 2020, 05:25 PM
 */

#ifndef VENTANAREGISTRAR_H
#define VENTANAREGISTRAR_H

#include <gtkmm.h>

#include "Usuario.h"
#include "VentanaIniciarSesion.h"
#include "RegistrarUsuarioBusiness.h"

class VentanaRegistrar : public Gtk::Window {
public:
    VentanaRegistrar();

    void init();
    void seleccionarGuardar();
    void seleccionarImprimir();

    Gtk::Fixed fixed;

    Gtk::Button btnRegistrar;
    Gtk::Button btnImprimir;

    Gtk::Entry entryNombre;
    Gtk::Entry entryEdad;
    Gtk::Entry entryNacionalidad;
    Gtk::Entry entryNumeroPasaporte;
    Gtk::Entry entryGenero;

    Gtk::Label lblEdad;
    Gtk::Label lblNombre;
    Gtk::Label lblNacionalidad;
    Gtk::Label lblNumeroPasaporte;
    Gtk::Label lblGenero;

    vector<Usuario*> vectorUsuario;

private:
    RegistrarUsuarioBusiness* registrarUsuarioBusiness;
};

#endif /* VENTANAREGISTRAR_H */

