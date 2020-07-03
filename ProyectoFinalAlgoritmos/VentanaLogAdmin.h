/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaLogAdmin.h
 * Author: raquel
 *
 * Created on 2 de julio de 2020, 16:55
 */

#ifndef VENTANALOGADMIN_H
#define VENTANALOGADMIN_H

#include <gtkmm.h>
#include "Administrador.h"
#include "VentanaAdministracion.h"
class VentanaLogAdmin : public Gtk::Window {
public:
    VentanaLogAdmin();
    void accionIniciarSesion();
    void iniciarSesion();
    void init();
    void AboutWinClose();
    //    VentanaLogAdmin(const VentanaLogAdmin& orig);
    //    virtual ~VentanaLogAdmin();
private:
    Gtk::Fixed fixed;

    Gtk::Button btnIniciarSesion;
    //    Gtk::Button btnEscogerVuelo;

    Gtk::Entry entryNombre;
    Gtk::Entry entryPassword;
    
    Gtk::Label lblNombre;
    Gtk::Label lblPassword;
    
    Administrador admin;
    
    VentanaAdministracion* ventanaAdministracion;
};

#endif /* VENTANALOGADMIN_H */

