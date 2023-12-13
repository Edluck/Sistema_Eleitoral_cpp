#include <iostream>
#include <string>
#include "libs/Candidato.h"

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

    if(nm_tipo_destinacao_votos.compare("legenda") == 0) {
        this->nm_tipo_destinacao_votos = true;
    } else {
        this->nm_tipo_destinacao_votos = false;
    }
}

