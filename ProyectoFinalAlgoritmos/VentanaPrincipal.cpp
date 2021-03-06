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
    this->set_title("Connection Travel");
    init();
}//Construcotr

void VentanaPrincipal::init() {
    this->fixed.put(this->menuBar, 0, 0); // se agrega el menuBar al contenedor fixed

    this->menuGestionarVuelos.set_label("Gestionar Vuelos");
    this->menuBar.append(this->menuGestionarVuelos);
    this->menuGestionarVuelos.set_submenu(this->subMenuArchivo);

    this->menuRegistrar.set_label("Registrar Usuario");
    this->ventanaRegistrar = 0;
    this->menuRegistrar.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaRegistrar));
    this->subMenuArchivo.append(this->menuRegistrar);

    this->menuInicarSesion.set_label("Iniciar Sesion");
    this->ventanaIniciarSesion = 0;
    this->menuInicarSesion.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaIniciarSesion));
    this->subMenuArchivo.append(this->menuInicarSesion);

    this->menuTransito.set_label("Transito");
    this->ventanaTransito = 0;
    this->menuTransito.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaTransito));
    this->subMenuTransito.append(this->menuTransito);
    
    this->menuGestionTransito.set_label("Transito Aereo");
    this->menuBar.append(this->menuGestionTransito);
    this->menuGestionTransito.set_submenu(this->subMenuTransito);
    
    this->menuAdministrador.set_label("Administracion");
    this->ventanaAdministrador = 0;
    this->menuAdministrador.signal_activate().connect(sigc::mem_fun(*this, &VentanaPrincipal::abrirVentanaAdministrador));
    this->subMenuAdministrador.append(this->menuAdministrador);

    this->menuGestionAdministrador.set_label("Administrador");
    this->menuBar.append(this->menuGestionAdministrador);
    this->menuGestionAdministrador.set_submenu(this->subMenuAdministrador);
    
    this->add(this->fixed);
    this->show_all_children();
}//init


void VentanaPrincipal::abrirVentanaAdministrador() {
   if (this->ventanaAdministrador != 0)
        return;
    this->ventanaAdministrador = new VentanaLogAdmin();
    this->ventanaAdministrador->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaAdministrador->show();
}//abrirVentanaAdministrador

void VentanaPrincipal::abrirVentanaTransito() {
 if (this->ventanaTransito != 0)
        return;
    this->ventanaTransito = new VentanaTransito();
    this->ventanaTransito->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaTransito->show();
}//abrirVentanaTransito

void VentanaPrincipal::abrirVentanaIniciarSesion() {
    if (this->ventanaIniciarSesion != 0)
        return;
    this->ventanaIniciarSesion = new VentanaIniciarSesion();
    this->ventanaIniciarSesion->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaIniciarSesion->show();
}//abrirVentanaEscogerAerolinea

void VentanaPrincipal::abrirVentanaRegistrar() {
    if (this->ventanaRegistrar != 0)
        return;
    this->ventanaRegistrar = new VentanaRegistrar();
    this->ventanaRegistrar->signal_hide().connect(sigc::mem_fun(*this, &VentanaPrincipal::aboutWinClose));
    this->ventanaRegistrar->show();
}//abrirVentanaEscogerAerolinea

void VentanaPrincipal::aboutWinClose() {
    this->ventanaIniciarSesion = 0;
    this->ventanaRegistrar = 0;
    this->ventanaTransito = 0;
    this->ventanaAdministrador=0;
}//aboutWinClose
