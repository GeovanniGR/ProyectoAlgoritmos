/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VentanaEscogerAerolinea.cpp
 * Author: geovanni
 * 
 * Created on 8 de junio de 2020, 04:02 PM
 */

#include "VentanaEscogerAerolinea.h"
#include "ListaAerolineas.h"
#include "Aerolinea_1.h"
VentanaEscogerAerolinea::VentanaEscogerAerolinea() {
    this->set_size_request(800, 600);
    this->set_title("Aerolineas Disponibles");
    loadaerolineas();
    init();
}//Constructor

void VentanaEscogerAerolinea::init() {
    this->etAerolinea.set_text(this->aerolineas.firstInlist());
    this->fixed.put(this->etAerolinea, 320, 250);

    this->btnArriba.add_pixlabel("assets/arriba.png", "");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedUp));
    this->fixed.put(this->btnArriba, 365, 150);

    this->btnAbajo.add_pixlabel("assets/abajo.png", "");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedDown));
    this->fixed.put(this->btnAbajo, 365, 300);

    this->btnConfirmarAerolinea.set_label("Confirmar Aerolinea");
    this->btnConfirmarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirm));
    this->fixed.put(this->btnConfirmarAerolinea, 330, 450);

    this->add(this->fixed);
    this->show_all_children();

}//init

void VentanaEscogerAerolinea::loadaerolineas() {
    Aerolinea a1 = Aerolinea("Avianca");
    Aerolinea a2 = Aerolinea("CopaAirlines");
    Aerolinea a3 = Aerolinea("Emiratos");
    Aerolinea a4 = Aerolinea("BlueJet");
    Aerolinea a5 = Aerolinea("Delta");

    this->aerolineas.insert(a1.getNombre());
    this->aerolineas.insert(a2.getNombre());
    this->aerolineas.insert(a3.getNombre());
    this->aerolineas.insert(a4.getNombre());
    this->aerolineas.insert(a5.getNombre());
    //    this->aerolineas.insert("Avianca");
    //    this->aerolineas.insert("CopaAirlines");
    //    this->aerolineas.insert("Emiratos");
    //    this->aerolineas.insert("BlueJet");
}

void VentanaEscogerAerolinea::onButtonClickedConfirm() {

}

void VentanaEscogerAerolinea::onButtonClickedDown() {
    this->etAerolinea.set_text(this->aerolineas.showNext(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::onButtonClickedUp() {
    this->etAerolinea.set_text(this->aerolineas.showPrevious(this->etAerolinea.get_text().raw()));

}//onButtonClickedDown
