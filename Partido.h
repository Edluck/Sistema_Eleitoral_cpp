#ifndef PARTIDOS_H
#define PARTIDOS_H
#include <map>
#include <string>
#include "Candidato.h"

class Partido
{
    string sg_partido;
    int nr_partido;
    map<int, Candidato> candidatos;
    int votos_legenda;
    int votos_nominais_total;
    int votos_totais;

public:
    Partido();
    Partido(string nome, int nr_partido);
    const int &getVotosTotais() const;
    const int &getVotosNominaisTotal() const;
    void addVotosLegenda(int votos);
    void calculaVotosTotais();
    const int &getVotosLegenda() const;
    const string &getSg_partido() const;
    const int &getNr_partido() const;
    void addCandidato(const Candidato &c);
    map<int, Candidato> &getCandidatos() ;
    void imprimePartido();
};

#endif