/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaRegistrar.cpp
 * Author: gerald
 * 
 * Created on 8 de junio de 2020, 05:25 PM
 */

#include "VentanaRegistrar.h"
#include "Validar.h"
#include <iostream>

using namespace std;

VentanaRegistrar::VentanaRegistrar(RegistrarUsuarioBusiness* business) {
    this->set_size_request(800, 600);
    this->registrarUsuarioBusiness = business;
    this->set_title("Registrar Usuario");
    init();
}

//VentanaRegistrar::VentanaRegistrar(const VentanaRegistrar& orig) {
//}
//
//VentanaRegistrar::~VentanaRegistrar() {
//}

void VentanaRegistrar::init() {
    this->btnRegistrar.set_label("Registrar");
    this->btnRegistrar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaRegistrar::seleccionarGuardar));
    this->fixed.put(this->btnRegistrar, 220, 550);

    this->btnImprimir.set_label("Imprimir");
    this->btnImprimir.signal_clicked().connect(sigc::mem_fun(*this, &VentanaRegistrar::seleccionarImprimir));
    this->fixed.put(this->btnImprimir, 520, 550);

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

    this->add(this->fixed);
    this->show_all_children();
}

void VentanaRegistrar::seleccionarGuardar() {
    if (this->entryNombre.get_text() == "" || this->entryEdad.get_text() == "" ||
            this->entryGenero.get_text() == "" || this->entryNacionalidad.get_text() == "" ||
            this->entryNumeroPasaporte.get_text() == "") {
        Gtk::MessageDialog dialogo(*this, "Complete los datos", false, Gtk::MESSAGE_QUESTION);
        dialogo.set_secondary_text("");
        dialogo.run();
    }//if
    else {
        if (Validar::validar_Es_Letra(this->entryNombre.get_text().raw()) &&
                Validar::validar_Es_Letra(this->entryGenero.get_text().raw()) &&
                Validar::validar_Es_Letra(this->entryNacionalidad.get_text().raw())) {

            if (Validar::validar_Es_Numero(this->entryEdad.get_text().raw()) &&
                    Validar::validar_Es_Numero(this->entryNumeroPasaporte.get_text().raw())) {
                string nombre = this->entryNombre.get_text().raw();
                int edad = std::stoi(entryEdad.get_text().raw());
                string genero = this->entryGenero.get_text().raw();
                int numPasaporte = std::stoi(entryNumeroPasaporte.get_text().raw());
                string nacionalidad = this->entryNacionalidad.get_text().raw();


                Usuario* usuario1 = new Usuario(nombre, edad, genero, numPasaporte, nacionalidad);

                if (this->registrarUsuarioBusiness->registrarUsuario(usuario1)) {
                    Gtk::MessageDialog dialogo(*this, "¡Registrado con exito!", false, Gtk::MESSAGE_INFO);

                    dialogo.run();
                } else {
                    Gtk::MessageDialog dialogo(*this, "¡No registrado egistrado!", false, Gtk::MESSAGE_INFO);

                    dialogo.run();
                }
            }
        }

        //this->ventanIniciarSesion = new VentanaIniciarSesion(usuario1);
        // this->ventanIniciarSesion.setUsuario(vectorUsuario);
    }
}//seleccionarGuardar

void VentanaRegistrar::seleccionarImprimir() {
    for (int i = 0; i < vectorUsuario.size(); i++) {
        cout << vectorUsuario.at(i)->toString() << endl;
    }//for

}//seleccionarImprimir