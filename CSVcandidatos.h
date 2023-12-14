 /* colunas do arquivo de candidatos com as informacoes que precisamos   
    CD_CARGO =  13,
    CD_SITUACAO_CANDIDATO_TOT = 68,
    NR_CANDIDATO = 16,
    NM_URNA_CANDIDATO = 18,
    NR_PARTIDO = 27,
    SG_PARTIDO = 28,
    NR_FEFERACAO = 30,
    DT_NASCIMENTO = 42,
    CD_SIT_TOT_TURNO = 56,
    CD_GENERO = 45,
    NM_TIPO_DESTINACAO_VOTOS = 67,
    
 */

#ifndef CSVCANDIDATOS_H
#define CSVCANDIDATOS_H
#include "Partido.h"
#include "Candidato.h"

class CSVcandidatos {
   static string diretorio_arq_cand;

   public:
   static void candidatosReader(const string &tipo_deputado, const string &arquivo_cand, string data_eleicao,
                                     map<int, Candidato> &candidatos, map<int, Partido> &partidos);
};


#endif