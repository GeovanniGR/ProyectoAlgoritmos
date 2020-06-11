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
    llenarComboPaisDestino();
    llenarComboPaisOrigen();
    init();
}//Constructor

void VentanaEscogerAerolinea::init() {
    this->fixed.put(this->cbPaisDestino, 400, 100);
    this->fixed.put(this->cbPaisOrigen, 400, 50);
    this->fixed.put(this->cbHorario, 400, 150);

    this->btnCargarItinerario.set_label("Cargar Itinerario");
    this->btnCargarItinerario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::cargarItinerario));
    this->fixed.put(this->btnCargarItinerario, 300, 450);

    this->etAerolinea.set_text(this->aerolineas.firstInlist());
    this->fixed.put(this->etAerolinea, 20, 150);

    this->lblPaisOrigen.set_text("Despegue");
    this->fixed.put(this->lblPaisOrigen, 300, 50);

    this->lblPaisDestino.set_text("Destino");
    this->fixed.put(this->lblPaisDestino, 300, 100);

    this->lblHorario.set_text("Horario");
    this->fixed.put(this->lblHorario, 300, 150);

    this->btnArriba.add_pixlabel("assets/arriba.png", "");
    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedUp));
    this->fixed.put(this->btnArriba, /*36*/50, /*1*/50);

    this->btnAbajo.add_pixlabel("assets/abajo.png", "");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedDown));
    this->fixed.put(this->btnAbajo, /*36*/50, /*3*/200);

    this->btnConfirmarAerolinea.set_label("Confirmar Aerolinea");
    this->btnConfirmarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirm));
    this->fixed.put(this->btnConfirmarAerolinea, /*33*/20, 350);

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

void VentanaEscogerAerolinea::cargarItinerario() {

}

void VentanaEscogerAerolinea::llenarComboPaisOrigen() {
    vector<string> vectorPaisOrigen;
    vectorPaisOrigen.push_back("Costa Rica");
    vectorPaisOrigen.push_back("Mexico");
    vectorPaisOrigen.push_back("Egipto");
    vectorPaisOrigen.push_back("Chinaaa");
    for (int i = 0; i < vectorPaisOrigen.size(); i++) {
        this->cbPaisOrigen.append(vectorPaisOrigen.at(i));
    }
}

void VentanaEscogerAerolinea::llenarComboPaisDestino() {
    vector<string> vectorPaisDestino;
    vectorPaisDestino.push_back("Costa Rica");
    vectorPaisDestino.push_back("Mexico");
    vectorPaisDestino.push_back("EEUU");
    vectorPaisDestino.push_back("Japon");
    for (int i = 0; i < vectorPaisDestino.size(); i++) {
        this->cbPaisDestino.append(vectorPaisDestino.at(i));
    }
}
