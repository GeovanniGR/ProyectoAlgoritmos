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

    this->btnCargarItinerario.set_label("Cargar Itinerario");
    this->btnCargarItinerario.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::cargarItinerario));
    this->fixed.put(this->btnCargarItinerario, 300, 450);

    this->btnConfirmarVuelo.set_label("Confirmar Vuelo");
    this->btnConfirmarVuelo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirmarVuelo));
    this->fixed.put(this->btnConfirmarVuelo, 450, 450);

    this->etAerolinea.set_text(this->aerolineas.firstInlist());
    this->fixed.put(this->etAerolinea, 20, 150);

    this->lblPaisOrigen.set_text("Despegue");
    this->fixed.put(this->lblPaisOrigen, 300, 50);

    this->lblPaisDestino.set_text("Destino");
    this->fixed.put(this->lblPaisDestino, 300, 100);

    this->btnArriba.add_pixlabel("assets/arriba.png", "");

    this->btnArriba.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedUp));
    this->fixed.put(this->btnArriba, 50, 50);

    this->btnAbajo.add_pixlabel("assets/abajo.png", "");
    this->btnAbajo.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedDown));
    this->fixed.put(this->btnAbajo, 50, 200);

    this->btnConfirmarAerolinea.set_label("Confirmar Aerolinea");
    this->btnConfirmarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedConfirm));
    this->fixed.put(this->btnConfirmarAerolinea, 20, 350);

    this->btnReestablecer.set_label("Reestablecer");
    this->btnReestablecer.signal_clicked().connect(sigc::mem_fun(*this, &VentanaEscogerAerolinea::onButtonClickedReestablecer));
    this->fixed.put(this->btnReestablecer, 20, 400);

    this->m_TreeView.set_size_request(200, 200);

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
    pd1.setPosX(4);
    pd1.setPosY(50);
    pd2.setPosX(40);
    pd2.setPosY(250);
    pd3.setPosX(75);
    pd3.setPosY(450);
    pd4.setPosX(400);
    pd4.setPosY(100);
    this->PaisesDes.push_back(pd1);
    this->PaisesDes.push_back(pd2);
    this->PaisesDes.push_back(pd3);
    this->PaisesDes.push_back(pd4);
    vector<Pais> paisOrigen;
    vector<PaisDestino> paisDestino;

    //cargarGrafo
    p.setPosX(4);
    p.setPosY(50);
    p1.setPosX(40);
    p1.setPosY(250);
    p2.setPosX(75);
    p2.setPosY(450);
    p3.setPosX(400);
    p3.setPosY(100);
    this->grafo->agregarNodo("Mexico");
    this->grafo->agregarNodo("Colombia");
    this->grafo->agregarNodo("Emiratos");
    this->grafo->agregarNodo("Costa Rica");
    this->nombrePais.push_back(p);
    this->nombrePais.push_back(p1);
    this->nombrePais.push_back(p2);
    this->nombrePais.push_back(p3);
    this->grafo->setNombresNodos(this->nombrePais);
    this->grafo->setPaisDes(this->PaisesDes);
    //a1 "Avianca"
    paisOrigen.push_back(p);
    paisOrigen.push_back(p1);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a1 = Aerolinea("Avianca", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a2 "CopaAirlines"
    paisOrigen.push_back(p3);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd1);
    a2 = Aerolinea("CopaAirlines", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a3 "Emiratos"
    paisOrigen.push_back(p);
    paisOrigen.push_back(p2);
    paisDestino.push_back(pd2);
    paisDestino.push_back(pd4);
    a3 = Aerolinea("Emiratos", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a4 "BlueJet"
    paisOrigen.push_back(p1);
    paisOrigen.push_back(p3);
    paisDestino.push_back(pd4);
    paisDestino.push_back(pd1);
    a4 = Aerolinea("BlueJet", paisOrigen, paisDestino);
    paisOrigen.clear();
    paisDestino.clear();

    //a5 "Delta"
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
}//loadaerolineas

void VentanaEscogerAerolinea::onButtonClickedConfirm() {
    llenarComboPaisDestino();
    llenarComboPaisOrigen();
}//onButtonClickedConfirm

void VentanaEscogerAerolinea::onButtonClickedDown() {
    this->etAerolinea.set_text(this->aerolineas.showNext(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::onButtonClickedUp() {
    this->etAerolinea.set_text(this->aerolineas.showPrevious(this->etAerolinea.get_text().raw()));
}//onButtonClickedDown

void VentanaEscogerAerolinea::cargarItinerario() {
    llenarColasItinerario();
    compararHoras();

}//cargarItinerario

void VentanaEscogerAerolinea::clear() {
    this->m_refTreeModel.clear();
}//clear

void VentanaEscogerAerolinea::compararHoras() {
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);
    stringstream s;
    time_t now = time(0);
    tm calendar_time = *std::localtime(std::addressof(now));
    vector<string> prueba;
    
    for (int i = 0; i < vectorHorarioDeSalida.size(); i++) {
        if (vectorHorarioDeSalida.at(i) >= calendar_time.tm_hour) {
            s << vectorHorarioDeSalida.at(i) << ":00" << " ---> " << vectHorarioDeLlegada.at(i) << ":00";
            prueba.push_back(s.str());
            s.str("");
        }//if
    }//for
    
    for (int i = 0; i < prueba.size(); i++) {
        Gtk::TreeModel::Row row = *(m_refTreeModel->append());
        row[m_Columns.m_col_salida] = prueba.at(i);
    }//for
    m_TreeView.append_column("HORARIOS", m_Columns.m_col_salida);
}

void VentanaEscogerAerolinea::llenarComboPaisOrigen() {
    if (this->etAerolinea.get_text().raw() == a1.getNombre()) {
        for (int i = 0; i < a1.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a1.getPaisOrigen().at(i).getPais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a2.getNombre()) {
        for (int i = 0; i < a2.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a2.getPaisOrigen().at(i).getPais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a3.getNombre()) {
        for (int i = 0; i < a3.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a3.getPaisOrigen().at(i).getPais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a4.getNombre()) {
        for (int i = 0; i < a4.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a4.getPaisOrigen().at(i).getPais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a5.getNombre()) {
        for (int i = 0; i < a5.getPaisOrigen().size(); i++) {
            this->cbPaisOrigen.append(a5.getPaisOrigen().at(i).getPais());
        }//for
    }//if
}//llenarComBoxOrigen

void VentanaEscogerAerolinea::llenarComboPaisDestino() {
    if (this->etAerolinea.get_text().raw() == a1.getNombre()) {
        for (int i = 0; i < a1.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a1.getPaisDestino().at(i).getNombrePais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a2.getNombre()) {
        for (int i = 0; i < a2.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a2.getPaisDestino().at(i).getNombrePais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a3.getNombre()) {
        for (int i = 0; i < a3.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a3.getPaisDestino().at(i).getNombrePais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a4.getNombre()) {
        for (int i = 0; i < a4.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a4.getPaisDestino().at(i).getNombrePais());
        }//for
    }//if

    if (this->etAerolinea.get_text().raw() == a5.getNombre()) {
        for (int i = 0; i < a5.getPaisDestino().size(); i++) {
            this->cbPaisDestino.append(a5.getPaisDestino().at(i).getNombrePais());
        }//for
    }//if
}//llenarComboBoxDestino

void VentanaEscogerAerolinea::onButtonClickedConfirmarVuelo() {
    //como obtener los datos para el grafo
    this->grafo->insertarArista(this->cbPaisOrigen.get_active_text(), this->cbPaisDestino.get_active_text());
    Glib::RefPtr<Gtk::TreeSelection> selection = this->m_TreeView.get_selection();
    Gtk::TreeModel::iterator selectedRow = selection->get_selected();
    Gtk::TreeModel::Row row = *selectedRow;
    Glib::ustring port = row.get_value(m_Columns.m_col_salida);
}

void VentanaEscogerAerolinea::onButtonClickedReestablecer() {
    this->cbPaisDestino.remove_all();
    this->cbPaisOrigen.remove_all();
    this->m_TreeView.remove_all_columns();
}//onButtonClickedReestablecer

void VentanaEscogerAerolinea::llenarColasItinerario() {
    Cola colaSalida;
    Cola colaLlegada;

    //Itinerario Avianca
    colaSalida.encolar(7);
    colaSalida.encolar(0);
    colaLlegada.encolar(5);
    colaLlegada.encolar(3);
    Itinerario it1(a1, p, pd4);
    it1.setHorariosSalida(colaSalida);
    it1.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    // Itinerario Avianca
    colaSalida.encolar(17);
    colaSalida.encolar(22);
    colaLlegada.encolar(15);
    colaLlegada.encolar(19);
    Itinerario it2(a1, p1, pd1);
    it2.setHorariosSalida(colaSalida);
    it2.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "CopaAirlines"
    colaSalida.encolar(0);
    colaSalida.encolar(9);
    colaLlegada.encolar(1);
    colaLlegada.encolar(7);
    Itinerario it3(a2, p3, pd2);
    it3.setHorariosSalida(colaSalida);
    it3.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "CopaAirlines"
    colaSalida.encolar(0);
    colaSalida.encolar(16);
    colaLlegada.encolar(1);
    colaLlegada.encolar(7);
    Itinerario it4(a2, p2, pd1);
    it4.setHorariosSalida(colaSalida);
    it4.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Emiratos"
    colaSalida.encolar(18);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(12);
    Itinerario it5(a3, p, pd2);
    it5.setHorariosSalida(colaSalida);
    it5.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Emiratos"
    colaSalida.encolar(7);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(11);
    Itinerario it6(a3, p2, pd4);
    it6.setHorariosSalida(colaSalida);
    it6.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "BlueJet"
    colaSalida.encolar(15);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(16);
    Itinerario it7(a4, p1, pd4);
    it7.setHorariosSalida(colaSalida);
    it7.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "BlueJet"
    colaSalida.encolar(22);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(18);
    Itinerario it8(a4, p3, pd1);
    it8.setHorariosSalida(colaSalida);
    it8.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Delta"
    colaSalida.encolar(15);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(23);
    Itinerario it10(a5, p1, pd3);
    it10.setHorariosSalida(colaSalida);
    it10.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //Itinerario "Delta"
    colaSalida.encolar(22);
    colaSalida.encolar(0);
    colaLlegada.encolar(1);
    colaLlegada.encolar(22);
    Itinerario it9(a5, p, pd2);
    it9.setHorariosSalida(colaSalida);
    it9.setHorariosLlegada(colaLlegada);
    colaLlegada.destruirCola();
    colaSalida.destruirCola();

    //vector de itinerarios
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

    for (int i = 0; i < horarios.size(); i++) {
        if (horarios.at(i).getAerolinea().getNombre() == this->etAerolinea.get_text().raw() &&
                horarios.at(i).getPaisorigen().getPais() == this->cbPaisOrigen.get_active_text() &&
                horarios.at(i).getPaisdestino().getNombrePais() == this->cbPaisDestino.get_active_text()) {
            vectorHorarioDeSalida = horarios.at(i).getHorariosSalida().mostrarCola();
            vectHorarioDeLlegada = horarios.at(i).getHorariosLlegada().mostrarCola();
            this->grafo->horarios(vectorHorarioDeSalida, vectHorarioDeLlegada);
        }
    }
}//llenar colas
