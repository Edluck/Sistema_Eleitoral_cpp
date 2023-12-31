#include "Partido.h"
#include "Candidato.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

Partido::Partido() {}

Partido::Partido(string nome, int nr_partido) {
    this->sg_partido = nome;
    this->nr_partido = nr_partido;
    this->votos_legenda = 0;
    this->votos_nominais_total = 0;
    this->votos_totais = 0;
}

const int &Partido::getVotosTotais() const {
    return votos_totais;
}

const int &Partido::getVotosNominaisTotal() const {
    return votos_nominais_total;
}

void Partido::addVotosLegenda(int votos) {
    this->votos_legenda += votos;   
}

void Partido::calculaVotosTotais() {
    for(auto &candidatos : this->candidatos) {
        if(candidatos.second.getCd_situacao_candidato_tot() == 2 || candidatos.second.getCd_situacao_candidato_tot() == 16)
        this->votos_nominais_total += candidatos.second.getQtd_votos();
    }
    this->votos_totais = this->votos_nominais_total + this->votos_legenda;
}

const int &Partido::getVotosLegenda() const {
    return votos_legenda;
}

const string &Partido::getSg_partido() const {
    return sg_partido;
}

const int &Partido::getNr_partido() const {
    return nr_partido;
}

map<int, Candidato> &Partido::getCandidatos() {
    return candidatos;
}

void Partido::addCandidato(const Candidato &c) {
    this->candidatos.insert(pair<int, Candidato>(c.getNr_candidato(), c));
}

void Partido::imprimePartido(){
    cout << this->sg_partido << " - " << this->nr_partido << ",";
}