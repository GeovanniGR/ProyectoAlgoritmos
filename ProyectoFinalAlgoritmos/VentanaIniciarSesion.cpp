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
    this->registrarUsuarioBusiness=RegistrarUsuarioBusiness::getInstance();
    init();
}//constructor

void VentanaIniciarSesion::init() {

    this->btnIniciarSesion.set_label("Iniciar Sesion");
    this->btnIniciarSesion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaIniciarSesion::iniciarSesion));
    this->fixed.put(this->btnIniciarSesion, 220, 550);

    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 20, 100);
    this->fixed.put(this->entryNombre, 160, 95);

    this->lblEdad.set_label("Edad: ");
    this->fixed.put(this->lblEdad, 20, 200);
    this->fixed.put(this->entryEdad, 160, 195);

    this->lblGenero.set_label("Genero:");
    this->fixed.put(this->lblGenero, 20, 300);
    this->fixed.put(this->entryGenero, 160, 295);

    this->lblNacionalidad.set_label("Nacionalidad: ");
    this->fixed.put(this->lblNacionalidad, 20, 400);
    this->fixed.put(this->entryNacionalidad, 160, 395);

    this->lblNumeroPasaporte.set_label("Numero de pasaporte:");
    this->fixed.put(this->lblNumeroPasaporte, 20, 500);
    this->fixed.put(this->entryNumeroPasaporte, 160, 495);

    this->ventanaEscogerAerolineas = 0;
    this->add(this->fixed);
    this->show_all_children();
}//init

//void VentanaIniciarSesion::setUsuario(vector<Usuario*> usuarios) {
//    this->vectorUsuario = usuarios;
//}
//
//vector<Usuario*> VentanaIniciarSesion::getUsuario() {
//    return vectorUsuario;
//}//getUsuario

void VentanaIniciarSesion::accionIniciarSesion(Usuario* usuario1) {
    if (this->ventanaEscogerAerolineas != 0)
        return;

    this->ventanaEscogerAerolineas = new VentanaEscogerAerolinea(/*usuario1*/);
    this->ventanaEscogerAerolineas->signal_hide().connect(sigc::mem_fun(*this, &VentanaIniciarSesion::cerrarVentanaAerolineas));
    this->ventanaEscogerAerolineas->show();
}//accionIniciarSesion

void VentanaIniciarSesion::iniciarSesion() {
    if (this->entryNombre.get_text() == "" || this->entryGenero.get_text() == "" ||
            this->entryNacionalidad.get_text() == "" || this->entryNumeroPasaporte.get_text().size() == 0 ||
            this->entryEdad.get_text().size() == 0) {
        Gtk::MessageDialog dialogo(*this, "Complete los datos", false, Gtk::MESSAGE_QUESTION);
        dialogo.set_secondary_text("");
        dialogo.run();
    } else {
        if (Validar::validar_Es_Letra(this->entryNombre.get_text().raw()) &&
                Validar::validar_Es_Letra(this->entryGenero.get_text().raw()) &&
                Validar::validar_Es_Letra(this->entryNacionalidad.get_text().raw())) {

            if (Validar::validar_Es_Numero(this->entryEdad.get_text().raw()) &&
                    Validar::validar_Es_Numero(this->entryNumeroPasaporte.get_text().raw())) {

                string nombre = this->entryNombre.get_text().raw();
                int edad = stoi(this->entryEdad.get_text().raw());
                string genero = this->entryGenero.get_text().raw();
                int numPasaporte = stoi(this->entryNumeroPasaporte.get_text().raw());
                string nacionalidad = this->entryNacionalidad.get_text().raw();

                Usuario* usuario = new Usuario(nombre, edad, genero, numPasaporte, nacionalidad);

                if (this->registrarUsuarioBusiness->encotrarUsuario(usuario)) {

                    accionIniciarSesion(usuario);

                }//if 
                else {
                    Gtk::MessageDialog dialogo(*this, "Contraseña y/o nombre invalido", false, Gtk::MESSAGE_QUESTION);
                    dialogo.set_secondary_text("");
                    dialogo.run();
                }//else
            }//if
        }//if 
        else {
            Gtk::MessageDialog error(*this, "Datos no validos", false, Gtk::MESSAGE_QUESTION);
            error.set_secondary_text("");
            error.run();
        }//else
    }//else
}//iniciarSesion

void VentanaIniciarSesion::cerrarVentanaAerolineas() {
    this->ventanaEscogerAerolineas = 0;
}//cerrarMenu