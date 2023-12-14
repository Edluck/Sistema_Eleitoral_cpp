#include <iostream>
#include <string>
#include "Candidato.h"

using namespace std;

Candidato::Candidato() {}

Candidato::Candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string nm_urna_candidato,
        int nr_partido, string sg_partido, int nr_federacao, string dt_nascimento, int cd_sit_tot_turno,
        int cd_genero, string nm_tipo_destinacao_votos) {
    this->cd_cargo = cd_cargo;
    this->cd_situacao_candidato_tot = cd_situacao_candidato_tot;
    this->nr_candidato = nr_candidato;
    this->nm_urna_candidato = nm_urna_candidato;
    this->nr_partido = nr_partido;
    this->sg_partido = sg_partido;
    this->nr_federacao = nr_federacao;
    this->dt_nascimento = dt_nascimento;
    this->cd_sit_tot_turno = cd_sit_tot_turno;
    
    if(cd_genero == 4) {
        this->cd_genero = FEMININO;
    } else if (cd_genero == 2) {
        this->cd_genero = MASCULINO;
    }
    cout << nm_tipo_destinacao_votos << endl;
    if(nm_tipo_destinacao_votos.find("legenda")) {
        this->nm_tipo_destinacao_votos = true;
    } else {
        this->nm_tipo_destinacao_votos = false;
    }
}

int &Candidato::getCd_cargo() const {
    return (int &) cd_cargo;
}

int &Candidato::getCd_situacao_candidato_tot() const {
    return (int &) cd_situacao_candidato_tot;
}

int &Candidato::getNr_candidato() const {
    return (int &) nr_candidato;
}

string &Candidato::getNm_urna_candidato() const {
    return (string &) nm_urna_candidato;
}

int &Candidato::getNr_partido() const {
    return (int &) nr_partido;
}

string &Candidato::getSg_partido() const {
    return (string &) sg_partido;
}

int &Candidato::getNr_federacao() const {
    return (int &) nr_federacao;
}

string &Candidato::getDt_nascimento() const {
    return (string &) dt_nascimento;
}

int &Candidato::getCd_sit_tot_turno() const {
    return (int &) cd_sit_tot_turno;
}

Genero &Candidato::getCd_genero() const {
    return (Genero &) cd_genero;
}

bool &Candidato::getNm_tipo_destinacao_votos() const {
    return (bool &) nm_tipo_destinacao_votos;
}

void Candidato::setIdade(const string &dataEleicao) {
    int anoEleicao = stoi(dataEleicao.substr(0, 4));
    int anoNascimento = stoi(dt_nascimento.substr(0, 4));
    this->idade = anoEleicao - anoNascimento;
}

int &Candidato::getIdade() const {
    return (int &) idade;
}

void Candidato::addVotos(int n_votos) {
    this->qtd_votos += n_votos;
}

int &Candidato::getQtd_votos() const {
    return (int &) qtd_votos;
}

// BRUNO LAMAS (PSB, 16.473 votos)
void Candidato::imprimeCandidato() {
    cout << this->getNm_urna_candidato() << " " << "(" << this->getSg_partido() << ", " << this->getQtd_votos() << " votos)" << endl;
}




