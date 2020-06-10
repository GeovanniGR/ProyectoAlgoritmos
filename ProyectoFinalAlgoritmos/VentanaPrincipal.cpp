/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaPrincipal.cpp
 * Author: geovanni
 * 
 * Created on 8 de junio de 2020, 03:40 PM
 */

#include "VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal() {
    this->set_size_request(800, 600);
    this->set_title("Hooters");
    init();
}//Construcotr

void VentanaPrincipal::init() {
    this->fixed.put(this->menuBar, 0, 0); // se agrega el menuBar al contenedor fixed

    this->menuGestionarVuelos.set_label("Gestionar Vuelos");
    this->menuBar.append(this->menuGestionarVuelos);
    this->menuGestionarVuelos.set_submenu(this->subMenuArchivo);
    this->menuAerolinea.set_label("Escoger Aerolínea");
    this->ventanaEsgogerAerolinea=0;
    
    this->menuAerolinea.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaEscogerAerolinea));
    this->subMenuArchivo.append(this->menuAerolinea);


    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaPrincipal::abrirVentanaEscogerAerolinea() {
    if (this->ventanaEsgogerAerolinea != 0)
        return;
    this->ventanaEsgogerAerolinea = new VentanaEscogerAerolinea();
    this->ventanaEsgogerAerolinea->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaEsgogerAerolinea->show();
}//abrirVentanaEscogerAerolinea

void VentanaPrincipal::aboutWinClose() {
    this->ventanaEsgogerAerolinea = 0;
}//aboutWinClose






