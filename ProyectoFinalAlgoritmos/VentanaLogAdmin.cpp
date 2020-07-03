/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaLogAdmin.cpp
 * Author: raquel
 * 
 * Created on 2 de julio de 2020, 16:55
 */

#include "VentanaLogAdmin.h"
#include "Validar.h"

VentanaLogAdmin::VentanaLogAdmin() {
    this->set_size_request(800, 600);
    this->set_title("Iniciar Sesion");
    this->admin = Administrador();
    init();
}
void VentanaLogAdmin::init() {

    this->btnIniciarSesion.set_label("Iniciar Sesion");
    this->btnIniciarSesion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaLogAdmin::iniciarSesion));
    this->fixed.put(this->btnIniciarSesion, 220, 250);

    this->lblNombre.set_label("Nombre: ");
    this->fixed.put(this->lblNombre, 20, 100);
    this->fixed.put(this->entryNombre, 160, 95);

    this->lblPassword.set_label("Password: ");
    this->fixed.put(this->lblPassword, 20, 195);
    this->fixed.put(this->entryPassword, 160, 195);

    this->ventanaAdministracion=0;
    this->add(this->fixed);
    this->show_all_children();
}//init

void VentanaLogAdmin::accionIniciarSesion() {
        if (this->ventanaAdministracion != 0)
        return;

    this->ventanaAdministracion = new VentanaAdministracion();
    this->ventanaAdministracion->signal_hide().connect(sigc::mem_fun(*this, &VentanaLogAdmin::AboutWinClose));
    this->ventanaAdministracion->show();

}

void VentanaLogAdmin::iniciarSesion() {
   if (this->entryNombre.get_text() == "" || this->entryPassword.get_text().size() == 0) {
        Gtk::MessageDialog dialogo(*this, "Complete los datos", false, Gtk::MESSAGE_QUESTION);
        dialogo.set_secondary_text("");
        dialogo.run();
    } else {
        if (Validar::validar_Es_Letra(this->entryNombre.get_text().raw())) {

            if (Validar::validar_Es_Numero(this->entryPassword.get_text().raw())) {

                string nombre = this->entryNombre.get_text().raw();
                int numPasaporte = stoi(this->entryPassword.get_text().raw());

                if (this->admin.GetNombre() == nombre && this->admin.GetPassword() == numPasaporte) {
                    accionIniciarSesion();
                    this->entryNombre.set_text("");
                    this->entryPassword.set_text("");
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
}

//
//VentanaLogAdmin::VentanaLogAdmin(const VentanaLogAdmin& orig) {
//}
//
//VentanaLogAdmin::~VentanaLogAdmin() {
//}

void VentanaLogAdmin::AboutWinClose() {
    this->ventanaAdministracion = 0;
}//cerrarMenu