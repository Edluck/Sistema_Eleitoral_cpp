#include "GeraRelatorios.h"
#include <iostream>
#include <locale>

using namespace std;

void GeraRelatorios::geraRelatorio(string tipo_deputado, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    //locale brasilLocale("pt_BR.UTF-8");
    //cout.imbue(brasilLocale);

    int tipo_deputado_int = 0;
    if (tipo_deputado == "estadual")
    {
        tipo_deputado_int = 7;
    }
    else if (tipo_deputado == "federal")
    {
        tipo_deputado_int = 6;
    }
    geraRelatorio1(tipo_deputado_int, candidatos, partidos);
    geraRelatorio2(tipo_deputado_int, candidatos, partidos);
    geraRelatorio3(tipo_deputado_int, candidatos, partidos);
    geraRelatorio4(tipo_deputado_int, candidatos, partidos);
    geraRelatorio5(tipo_deputado_int, candidatos, partidos);
    geraRelatorio6(tipo_deputado_int, candidatos, partidos);
    geraRelatorio7(tipo_deputado_int, candidatos, partidos);
    geraRelatorio8(tipo_deputado_int, candidatos, partidos);
    geraRelatorio9(tipo_deputado_int, candidatos, partidos);
    geraRelatorio10(tipo_deputado_int, candidatos, partidos);
}

 void GeraRelatorios::GeraRelatorios::geraRelatorio1(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio2(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio3(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio4(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio5(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio6(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio7(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio8(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
}
 void GeraRelatorios::geraRelatorio9(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int qtd_masculino = 0;
    int qtd_feminino = 0;
    double porcentagem_masculino = 0;
    double porcentagem_feminino = 0;

    for(auto &candidato : candidatos)
    {   
        if((candidato.second.getCd_sit_tot_turno() == 2 || candidato.second.getCd_sit_tot_turno() == 3) && candidato.second.getCd_cargo() == tipo_deputado_int) {
        if(candidato.second.getCd_genero() == MASCULINO)
        {
            qtd_masculino++;
        }
        else if(candidato.second.getCd_genero() == FEMININO)
        {
            qtd_feminino++;
        }
        }
        //cout << candidato.second.getCd_cargo() << " " << candidato.second.getNm_urna_candidato() << " " << candidato.second.getQtd_votos() << endl;
    }

    porcentagem_masculino = ((double) qtd_masculino / (qtd_feminino + qtd_masculino)) * 100;
    porcentagem_feminino = ((double) qtd_feminino / (qtd_feminino + qtd_masculino)) * 100;

    cout << "\nEleitos, por gênero:" << endl;
    cout << "Feminino:  " << qtd_feminino << " (" << porcentagem_feminino << "%)" << endl;
    cout << "Masculino:  " << qtd_masculino << " (" << porcentagem_masculino << "%)" << endl;
}
 void GeraRelatorios::geraRelatorio10(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int total_votos_legenda = 0;
    int total_votos_nomimais = 0;
    int total_votos_validos = 0;
    double percentual_votos_legenda = 0;
    double percentual_votos_nomimais = 0;

    for (auto &partido : partidos)
    {
        partido.second.addVotosNominaisTotal();
        total_votos_legenda += partido.second.getVotosLegenda();
        total_votos_nomimais += partido.second.getVotosNominaisTotal();
    }

    total_votos_validos = total_votos_legenda + total_votos_nomimais;
    percentual_votos_legenda = ((double) total_votos_legenda / total_votos_validos) * 100;
    percentual_votos_nomimais = ((double) total_votos_nomimais / total_votos_validos) * 100;


    cout << "\nTotal de votos válidos:    " << total_votos_validos << endl;
    cout << "Total de votos nominais:    " << total_votos_nomimais << " (" << percentual_votos_nomimais << "%)" << endl;
    cout << "Total de votos de legenda: " << total_votos_legenda << " (" << percentual_votos_legenda << "%)" << endl;

}
