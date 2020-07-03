/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaAdministracion.cpp
 * Author: raquel
 * 
 * Created on 2 de julio de 2020, 17:32
 */

#include "VentanaAdministracion.h"

VentanaAdministracion::VentanaAdministracion() {
    this->set_size_request(800, 600);
    this->set_title("Administracion");
    init();
}

void VentanaAdministracion::init() {
    this->lblNombre.set_label("Nombre:");
    this->fixed.put(this->lblNombre, 20, 100);
    this->fixed.put(this->etNombre, 160, 90);

    this->lblPaisOrigen.set_label("Pais Origen: ");
    this->fixed.put(this->lblPaisOrigen, 20, 150);
    this->fixed.put(this->etPaisOrigen, 160, 130);

    this->lblPaisDestino.set_label("Pais Destino");
    this->fixed.put(this->lblPaisDestino, 20, 190);
    this->fixed.put(this->etPaisDestino, 160, 180);

    this->lblMigracion.set_label("Nacionalidad Migracion ");
    this->fixed.put(this->lblMigracion, 20, 230);
    this->fixed.put(this->etMigracion, 160, 250);
    
    
    this->btnAgregarPaises.set_label("Agregar Paises");
    this->btnAgregarPaises.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAdministracion::onButtonaddPaises));
    this->fixed.put(this->btnAgregarPaises, 20, 350);

     this->btnGuardarAerolinea.set_label("Guardar Aerolinea");
    this->btnGuardarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaAdministracion::onButtonGuardar));
    this->fixed.put(this->btnGuardarAerolinea, 20, 400);
    
    this->fixed.put(this->cbPaisDestino, 400, 100);
    this->fixed.put(this->cbPaisOrigen, 400, 50);

    this->add(this->fixed);
    this->show_all_children();
    //    this->lblNumeroPasaporte.set_label("Numero de pasaporte:");
    //    this->fixed.put(this->lblNumeroPasaporte, 20, 500);
    //    this->fixed.put(this->entryNumeroPasaporte, 160, 495);
}

void VentanaAdministracion::onButtonaddPaises() {
    this->paisOrigen = Pais(this->etPaisOrigen.get_text());
    this->paisesOrigen.push_back(this->paisOrigen);
    this->paisDestino = PaisDestino(this->etPaisDestino.get_text(),this->etMigracion.get_text());
    this->paisesDestino.push_back(this->paisDestino);
    this->cbPaisDestino.append(this->etPaisDestino.get_text());
    this->cbPaisOrigen.append(this->etPaisOrigen.get_text());
   
    this->etMigracion.set_text("");
    this->etPaisDestino.set_text("");
    this->etPaisOrigen.set_text("");
}

void VentanaAdministracion::onButtonGuardar() {
    this->aerolinea = Aerolinea(this->etNombre.get_text(),this->paisesOrigen,this->paisesDestino);
    this->aerolineas->insert(this->aerolinea);
    this->etNombre.set_text("");
}//


//VentanaAdministracion::VentanaAdministracion(const VentanaAdministracion& orig) {
//}
//
//VentanaAdministracion::~VentanaAdministracion() {
//}

