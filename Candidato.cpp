#include <iostream>
#include <string>
#include "Candidato.h"
#include <ctime>

#define SEC_PER_YEAR 31536000

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

    if(nm_tipo_destinacao_votos.find("legenda") != string::npos) {
        this->nm_tipo_destinacao_votos = true;
    } else {
        this->nm_tipo_destinacao_votos = false;
    }
}

const int &Candidato::getCd_cargo() const {
    return cd_cargo;
}

const int &Candidato::getCd_situacao_candidato_tot() const {
    return cd_situacao_candidato_tot;
}

const int &Candidato::getNr_candidato() const {
    return nr_candidato;
}

const string &Candidato::getNm_urna_candidato() const {
    return nm_urna_candidato;
}

const int &Candidato::getNr_partido() const {
    return nr_partido;
}

const string &Candidato::getSg_partido() const {
    return sg_partido;
}

const int &Candidato::getNr_federacao() const {
    return nr_federacao;
}

const string &Candidato::getDt_nascimento() const {
    return dt_nascimento;
}

const int &Candidato::getCd_sit_tot_turno() const {
    return cd_sit_tot_turno;
}

const Genero &Candidato::getCd_genero() const {
    return cd_genero;
}

const bool &Candidato::getNm_tipo_destinacao_votos() const {
    return nm_tipo_destinacao_votos;
}

void Candidato::setIdade(const string &dataEleicao) {
    //calculo da idade usando ctime
    tm nasc = {0};
    tm elei = {0};

    nasc.tm_mday = stoi(dt_nascimento.substr(0,2));
    nasc.tm_mon =  stoi(dt_nascimento.substr(3,2)) - 1;
    nasc.tm_year = stoi(dt_nascimento.substr(6,4)) - 1900; 

    elei.tm_mday = stoi(dataEleicao.substr(0,2));
    elei.tm_mon =  stoi(dataEleicao.substr(3,2)) - 1;
    elei.tm_year = stoi(dataEleicao.substr(6,4)) - 1900;

    double segundos_no_Ano = 60 * 60 * 24 * 365.2425; 
    this->idade = difftime(mktime(&elei), mktime(&nasc)) / segundos_no_Ano;
    
}

const int &Candidato::getIdade() const {
    return idade;
}

void Candidato::addVotos(int n_votos) {
    this->qtd_votos += n_votos;
}

const int &Candidato::getQtd_votos() const {
    return qtd_votos;
}

// BRUNO LAMAS (PSB, 16.473 votos)
void Candidato::imprimeCandidato() {
    string plural = "";
    if (this->getQtd_votos() > 1)
    {
        plural = "s";
    }
    
    cout << this->getNm_urna_candidato() << " " << "(" << this->getSg_partido() << ", " << this->getQtd_votos() << " voto" << plural <<")";
}



