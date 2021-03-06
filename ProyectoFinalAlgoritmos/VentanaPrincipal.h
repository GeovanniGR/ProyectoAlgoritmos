/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaPrincipal.h
 * Author: geovanni
 *
 * Created on 8 de junio de 2020, 03:40 PM
 */

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/menubar.h>
#include <gtkmm-3.0/gtkmm/menu.h>
#include <gtkmm-3.0/gtkmm/fixed.h>
#include <gtkmm-3.0/gtkmm/imagemenuitem.h>

#include "VentanaRegistrar.h"
#include "VentanaTransito.h"
#include "VentanaLogAdmin.h"

class VentanaPrincipal : public Gtk::Window {
public:
    VentanaPrincipal();
    void init();
    void abrirVentanaAdministrador();
    void abrirVentanaTransito();
    void abrirVentanaRegistrar();
    void abrirVentanaIniciarSesion();
    void aboutWinClose();
private:
    Gtk::MenuBar menuBar;

    Gtk::MenuItem menuGestionarVuelos;
    Gtk::MenuItem menuGestionTransito;
    Gtk::MenuItem menuGestionAdministrador;

    Gtk::Menu subMenuArchivo;
    Gtk::Menu subMenuTransito;
    Gtk::Menu subMenuAdministrador;

    Gtk::ImageMenuItem menuAerolinea;
    Gtk::ImageMenuItem menuRegistrar;
    Gtk::ImageMenuItem menuInicarSesion;
    Gtk::ImageMenuItem menuTransito;
    Gtk::ImageMenuItem menuAdministrador;

    Gtk::Fixed fixed; // contenedor
    
    VentanaLogAdmin* ventanaAdministrador;
    VentanaRegistrar* ventanaRegistrar;
    VentanaIniciarSesion* ventanaIniciarSesion;
    VentanaTransito* ventanaTransito;
    RegistrarUsuarioBusiness* registrarBusiness;
};

#endif /* VENTANAPRINCIPAL_H */

