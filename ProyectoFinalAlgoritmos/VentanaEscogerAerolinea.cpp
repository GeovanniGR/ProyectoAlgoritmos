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
#include "Pais.h"
#include "PaisDestino.h"
#include "Cola.h"
#include "Itinerario.h"
#include  <chrono>
#include <ctime>

VentanaEscogerAerolinea::VentanaEscogerAerolinea() {
    this->set_size_request(800, 600);
    this->set_title("Aerolineas Disponibles");
    loadaerolineas();
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

    this->m_TreeView.set_size_request(200, 200);
    //    this->cargarItinerario();
    this->fixed.put(this->m_TreeView, 300, 200);

    this->add(this->fixed);
    this->show_all_children();

}//init

void VentanaEscogerAerolinea::loadaerolineas() {
    //paises Origen
    this->p = Pais("Mexico");
    this->p1 = Pais("Colombia");
    this->p2 = Pais("Emiratos");
    this->p3 = Pais("Costa Rica");
    //paisesDestino
    this->pd1 = PaisDestino("Mexico");
    this->pd2 = PaisDestino("Colombia");
    this->pd3 = PaisDestino("Emiratos");
    this->pd4 = PaisDestino("Costa Rica");
    vector<Pais> paisOrigen;
    vector<PaisDestino> paisDestino;
    //a1
    paisOrigen.push_back(p);
    paisOrigen.push_back(p1);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a1 = Aerolinea("Avianca", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();
    //a2
    paisOrigen.push_back(p3);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd1);
    a2 = Aerolinea("CopaAirlines", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();
    //a3
    paisOrigen.push_back(p);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd4);
    a3 = Aerolinea("Emiratos", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();
    //a4
    paisOrigen.push_back(p1);
    paisOrigen.push_back(p3);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a4 = Aerolinea("BlueJet", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();
    //a5
    paisOrigen.push_back(p);
    paisOrigen.push_back(p1);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd3);
    a5 = Aerolinea("Delta", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();
    this->aerolineas.insert(a1.getNombre());
    this->aerolineas.insert(a2.getNombre());
    this->aerolineas.insert(a3.getNombre());
    this->aerolineas.insert(a4.getNombre());
    this->aerolineas.insert(a5.getNombre());
}

void VentanaEscogerAerolinea::onButtonClickedConfirm() {
    llenarComboPaisDestino();
    llenarComboPaisOrigen();

}

void VentanaEscogerAerolinea::onButtonClickedDown() {
    this->etAerolinea.set_text(this->aerolineas.showNext(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::onButtonClickedUp() {
    this->etAerolinea.set_text(this->aerolineas.showPrevious(this->etAerolinea.get_text().raw()));

}//onButtonClickedDown

void VentanaEscogerAerolinea::cargarItinerario() {
    //crear el tree model
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    Cola colaSalida;
    Cola colaLlegada;

    colaSalida.encolar(7);
    colaSalida.encolar(24);
    colaLlegada.encolar(5);
    colaLlegada.encolar(3);
    Itinerario it1(a1, p, pd4);
    it1.SetHorariosSalida(colaSalida);
    it1.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(24);
    colaSalida.encolar(5);
    colaLlegada.encolar(15);
    colaLlegada.encolar(19);
    Itinerario it2(a1, p1, pd1);
    it2.SetHorariosSalida(colaSalida);
    it2.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(24);
    colaSalida.encolar(9);
    colaLlegada.encolar(1);
    colaLlegada.encolar(7);
    Itinerario it3(a2, p3, pd2);
    it3.SetHorariosSalida(colaSalida);
    it3.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(7);
    Itinerario it4(a2, p2, pd1);
    it4.SetHorariosSalida(colaSalida);
    it4.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(12);
    Itinerario it5(a3, p, pd2);
    it5.SetHorariosSalida(colaSalida);
    it5.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(11);
    Itinerario it6(a3, p2, pd4);
    it6.SetHorariosSalida(colaSalida);
    it6.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(16);
    Itinerario it7(a4, p1, pd4);
    it7.SetHorariosSalida(colaSalida);
    it7.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(18);
    Itinerario it8(a4, p3, pd1);
    it8.SetHorariosSalida(colaSalida);
    it8.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(23);
    Itinerario it10(a5, p1, pd3);
    it10.SetHorariosSalida(colaSalida);
    it10.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    colaSalida.encolar(15);
    colaSalida.encolar(24);
    colaLlegada.encolar(1);
    colaLlegada.encolar(22);
    Itinerario it9(a5, p, pd2);
    it9.SetHorariosSalida(colaSalida);
    it9.SetHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    vector<Itinerario> horarios;
    horarios.push_back(it1);
    horarios.push_back(it2);
    horarios.push_back(it3);
    horarios.push_back(it4);
    horarios.push_back(it5);
    horarios.push_back(it6);
    horarios.push_back(it7);
    horarios.push_back(it8);
    horarios.push_back(it9);
    horarios.push_back(it10);
    vector<int> sirvaPorFa;
    vector<int> graciasPorServir;
    vector<string> prueba;
    stringstream s;
    time_t now = time(0);
    tm calendar_time = *std::localtime(std::addressof(now));
    for (int i = 0; i < horarios.size(); i++) {
        if (horarios.at(i).GetAerolinea().getNombre() == this->etAerolinea.get_text().raw() &&
                horarios.at(i).GetPaisorigen().GetPais() == this->cbPaisOrigen.get_active_text() &&
                horarios.at(i).getPaisdestino().GetNombrePais() == this->cbPaisDestino.get_active_text()) {
            sirvaPorFa = horarios.at(i).GetHorariosSalida().mostrarCola();
            graciasPorServir = horarios.at(i).GetHorariosLlegada().mostrarCola();
            for (int i = 0; i < sirvaPorFa.size(); i++) {
                cout << "for";
                if (sirvaPorFa.at(i) >= calendar_time.tm_hour) {
                    cout << "if";
                    s << sirvaPorFa.at(i) << ":00" << " ---> " << graciasPorServir.at(i) << ":00";
                    prueba.push_back(s.str());
                }
            }

            for (int i = 0; i < prueba.size(); i++) {
                Gtk::TreeModel::Row row = *(m_refTreeModel->append());
                row[m_Columns.m_col_salida] = prueba.at(i);
            }
        }//if
    }

    m_TreeView.append_column("HORARIOS", m_Columns.m_col_salida);
}

void VentanaEscogerAerolinea::clear() {
    this->m_refTreeModel.clear();
}

void VentanaEscogerAerolinea::llenarComboPaisOrigen() {
    if (this->etAerolinea.get_text().raw() == a1.getNombre()) {
        for (int i = 0; i < a1.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a1.getPaisOrigen().at(i).GetPais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a2.getNombre()) {
        for (int i = 0; i < a2.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a2.getPaisOrigen().at(i).GetPais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a3.getNombre()) {
        for (int i = 0; i < a3.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a3.getPaisOrigen().at(i).GetPais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a4.getNombre()) {
        for (int i = 0; i < a4.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a4.getPaisOrigen().at(i).GetPais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a5.getNombre()) {
        for (int i = 0; i < a5.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a5.getPaisOrigen().at(i).GetPais());
        }
    }
}

void VentanaEscogerAerolinea::llenarComboPaisDestino() {
    if (this->etAerolinea.get_text().raw() == a1.getNombre()) {
        for (int i = 0; i < a1.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a1.getPaisDestino().at(i).GetNombrePais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a2.getNombre()) {
        for (int i = 0; i < a2.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a2.getPaisDestino().at(i).GetNombrePais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a3.getNombre()) {
        for (int i = 0; i < a3.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a3.getPaisDestino().at(i).GetNombrePais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a4.getNombre()) {
        for (int i = 0; i < a4.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a4.getPaisDestino().at(i).GetNombrePais());
        }
    }
    if (this->etAerolinea.get_text().raw() == a5.getNombre()) {
        for (int i = 0; i < a5.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a5.getPaisDestino().at(i).GetNombrePais());
        }
    }
}
