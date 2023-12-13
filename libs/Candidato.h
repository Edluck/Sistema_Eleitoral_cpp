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
    int getCd_cargo();
    int getCd_situacao_candidato_tot();
    int getNr_candidato();
    string getNm_urna_candidato();
    int getNr_partido();
    string getSg_partido();
    int getNr_federacao();
    string getDt_nascimento();
    int getCd_sit_tot_turno();
    int getCd_genero();
    string getNm_tipo_destinacao_votos();
    void setIdade(string dataEleicao);
    int getIdade();
    void addVotos(int n_votos);
    int getQtd_votos();
};

    void imprimeCandidato();

#endif