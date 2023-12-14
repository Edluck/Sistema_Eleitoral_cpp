#include "Acervo.h"
#include <iostream>

using namespace std;

Acervo::Acervo(string tipo_deputado, string arq_cand, string arq_vot, string data_eleicao) {

    CSVcandidatos::candidatosReader(tipo_deputado, arq_cand, data_eleicao, this->candidatos, this->partidos);
    CSVvotacao::votacaoReader(tipo_deputado, arq_vot,  this->candidatos, this->partidos);

}

void Acervo::geraRelatorio(string tipo_deputado) {
    /*
    for(auto &candidato : candidatos)
    {   
        if((candidato.second.getCd_sit_tot_turno() == 2 || candidato.second.getCd_sit_tot_turno() == 3) && candidato.second.getCd_cargo() == 6) 
            candidato.second.imprimeCandidato();
        
    }
    */
    GeraRelatorios::geraRelatorio(tipo_deputado, this->candidatos, this->partidos);
}