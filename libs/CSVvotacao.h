/*
    colunas do arquivo de votacao necessaria para processar os votos
    CD_CARGO 17
    NR_NOTAVEL 19
    QT_VOTOS 21
 */

#ifndef CSVVOTACAO_H
#define CSVVOTACAO_H

#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>

#include "Candidato.h"
#include "CSVcandidatos.h"
#include "Partido.h"

class CSVvotacao {
    static string diretorio_arq_votacao;

    public:
    static void votacaoReader(string tipo_deputado, string arquivo_vot, map<int, Candidato> candidatos,
            map<int, Partido> partidos);
};

#endif