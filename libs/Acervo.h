#ifndef ACERVO_H
#define ACERVO_H
#include "Partido.h"
#include "Candidato.h"
#include "CSVcandidatos.h"
#include "CSVvotacao.h"
#include "GeraRelatorios.h"

class Acervo {
    map<int,Candidato> candidatos;
    map<int,Partido> partidos;

    public:
    Acervo(string tipo_deputado, string arq_cand, string arq_vot, string data_eleicao);
    void geraRelatorio(string tipo_deputado);
};


#endif