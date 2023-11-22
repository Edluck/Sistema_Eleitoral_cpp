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
    int getVotosTotais();
    int getVotosNominaisTotal();
    void addVotosLegenda(int votos);
    int getVotosLegenda();
    string getSg_partido();
    int getNr_partido();
    void addCandidato(Candidato c);
    map<int, Candidato> getCandidatos();
};

void imprimePartido();
#endif