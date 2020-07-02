/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaIniciarSesion.cpp
 * Author: gerald
 * 
 */

#include "VentanaIniciarSesion.h"
#include "Validar.h"

VentanaIniciarSesion::VentanaIniciarSesion() {
    this->set_size_request(800, 600);
    this->set_title("Iniciar Sesion");
    this->registrarUsuarioBusiness = RegistrarUsuarioBusiness::getInstance();
    init();
}//constructor

void VentanaIniciarSesion::init() {

    this->btnIniciarSesion.set_label("Iniciar Sesion");
    this->btnIniciarSesion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaIniciarSesion::iniciarSesion));
    this->fixed.put(this->btnIniciarSesion, 220, 250);

    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 20, 100);
    this->fixed.put(this->entryNombre, 160, 95);

    this->lblNumeroPasaporte.set_label("Numero de pasaporte:");
    this->fixed.put(this->lblNumeroPasaporte, 20, 195);
    this->fixed.put(this->entryNumeroPasaporte, 160, 195);

    this->ventanaEscogerAerolineas = 0;
    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaIniciarSesion::accionIniciarSesion(Usuario* usuario1) {
    if (this->ventanaEscogerAerolineas != 0)
        return;

    this->ventanaEscogerAerolineas = new VentanaEscogerAerolinea(usuario1);
    this->ventanaEscogerAerolineas->signal_hide().connect(sigc::mem_fun(*this, &VentanaIniciarSesion::cerrarVentanaAerolineas));
    this->ventanaEscogerAerolineas->show();
}//accionIniciarSesion

void VentanaIniciarSesion::iniciarSesion() {
    if (this->entryNombre.get_text() == "" || this->entryNumeroPasaporte.get_text().size() == 0) {
        Gtk::MessageDialog dialogo(*this, "Complete los datos", false, Gtk::MESSAGE_QUESTION);
        dialogo.set_secondary_text("");
        dialogo.run();
    } else {
        if (Validar::validar_Es_Letra(this->entryNombre.get_text().raw())) {

            if (Validar::validar_Es_Numero(this->entryNumeroPasaporte.get_text().raw())) {

                string nombre = this->entryNombre.get_text().raw();
                int numPasaporte = stoi(this->entryNumeroPasaporte.get_text().raw());

<Usuario* usuario = new Usuario(nombre, numPasaporte);
                this->usuario = new Usuario(nombre, numPasaporte);
                if (this->registrarUsuarioBusiness->encotrarUsuario(usuario)) {
                    accionIniciarSesion(this->registrarUsuarioBusiness->devolverUsuario(usuario));
                    this->entryNombre.set_text("");
                    this->entryNumeroPasaporte.set_text("");
                }//if 
                else {
                    Gtk::MessageDialog dialogo(*this, "Contraseña y/o nombre invalido", false, Gtk::MESSAGE_QUESTION);
                    dialogo.set_secondary_text("");
                    dialogo.run();
                }//else
            }//if
            else {
                Gtk::MessageDialog error(*this, "Dato(s) no valido(s)", false, Gtk::MESSAGE_QUESTION);
                error.run();
            }//else
        }//if 
        else {
            Gtk::MessageDialog error(*this, "Dato(s) no valido(s)", false, Gtk::MESSAGE_QUESTION);
            error.run();
        }//else
    }//else
}//iniciarSesion

void VentanaIniciarSesion::cerrarVentanaAerolineas() {
    this->ventanaEscogerAerolineas = 0;
}//cerrarMenu