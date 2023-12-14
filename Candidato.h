#ifndef CANDIDATOS_H
#define CANDIDATOS_H

#include <string>
#include <iostream>
using namespace std;

enum Genero {
    MASCULINO,
    FEMININO
};

class Candidato {
    int cd_cargo;
    int cd_situacao_candidato_tot;
    int nr_candidato;
    string nm_urna_candidato;
    int nr_partido;
    string sg_partido;
    int nr_federacao;
    string dt_nascimento;
    int cd_sit_tot_turno;
    Genero cd_genero;
    bool nm_tipo_destinacao_votos;

    int qtd_votos = 0;
    int idade = 0;

    public: 
    Candidato();
    Candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string nm_urna_candidato,
            int nr_partido, string sg_partido, int nr_federacao, string dt_nascimento, int cd_sit_tot_turno,
            int cd_genero, string nm_tipo_destinacao_votos);
    const int &getCd_cargo() const;
    const int &getCd_situacao_candidato_tot() const;
    const int &getNr_candidato() const;
    const string &getNm_urna_candidato() const;
    const int &getNr_partido() const;
    const string &getSg_partido() const;
    const int &getNr_federacao() const;
    const string &getDt_nascimento() const;
    const int &getCd_sit_tot_turno() const;
    const Genero &getCd_genero() const;
    const bool &getNm_tipo_destinacao_votos() const;
    void setIdade(const string &dataEleicao);
    const int &getIdade() const;
    void addVotos(int n_votos) ;
    const int &getQtd_votos() const;
    void imprimeCandidato();
};

#endif
