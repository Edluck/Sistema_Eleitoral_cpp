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

int &Partido::getVotosTotais() const {
    return (int &) votos_totais;
}

int &Partido::getVotosNominaisTotal() const {
    return (int &) votos_nominais_total;
}

void Partido::addVotosLegenda(int votos) {
    this->votos_legenda += votos;   
}

void Partido::addVotosNominaisTotal() {
    for(auto &candidatos : this->candidatos) {
        if(candidatos.second.getCd_situacao_candidato_tot() == 2 || candidatos.second.getCd_situacao_candidato_tot() == 16)
        this->votos_nominais_total += candidatos.second.getQtd_votos();
    }
}

int &Partido::getVotosLegenda() const {
    return (int &) votos_legenda;
}

string &Partido::getSg_partido() const {
    return (string &) sg_partido;
}

int &Partido::getNr_partido() const {
    return (int &) nr_partido;
}

void Partido::addCandidato(Candidato c) {
    this->candidatos.insert(pair<int, Candidato>(c.getNr_candidato(), c));
}