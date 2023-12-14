#include "Acervo.h"
#include <iostream>

using namespace std;

Acervo::Acervo(string tipo_deputado, string arq_cand, string arq_vot, string data_eleicao) {

    CSVcandidatos::candidatosReader(tipo_deputado, arq_cand, data_eleicao, this->candidatos, this->partidos);
    CSVvotacao::votacaoReader(arq_vot, data_eleicao,  this->candidatos, this->partidos);
}

void Acervo::geraRelatorio(string tipo_deputado) {
    GeraRelatorios::geraRelatorio(tipo_deputado, this->candidatos, this->partidos);
}