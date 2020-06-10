/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaEscogerAerolinea.h
 * Author: geovanni
 *
 * Created on 8 de junio de 2020, 04:02 PM
 */

#ifndef VENTANAESCOGERAEROLINEA_H
#define VENTANAESCOGERAEROLINEA_H
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/fixed.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/entry.h>

#include "ListaAerolineas.h"
#include "Aerolinea_1.h"
class VentanaEscogerAerolinea : public Gtk::Window {
public:
    VentanaEscogerAerolinea();
    void init();
    void onButtonClickedUp();
    void onButtonClickedDown();
    void onButtonClickedConfirm();
    void loadaerolineas();
private:
    ListaAerolineas aerolineas;
    Gtk::Fixed fixed;
    Gtk::Button btnArriba;
    Gtk::Button btnAbajo;
    Gtk::Entry etAerolinea;
    Gtk::Button btnConfirmarAerolinea;
   
    
};

#endif /* VENTANAESCOGERAEROLINEA_H */

